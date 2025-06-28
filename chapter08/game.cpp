/*
 * 파일명: simple_rpg_game.cpp
 * 
 * 간단한 텍스트 기반 RPG 게임
 * 프로젝트에서 배운 C++ 개념들을 종합적으로 활용
 * 
 * 컴파일: g++ -std=c++17 -o rpg_game simple_rpg_game.cpp
 * 실행: ./rpg_game
 */

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <map>

using namespace std;

// 게임 예외 클래스들
class GameException : public exception {
protected:
    string message;
public:
    explicit GameException(const string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class InvalidActionException : public GameException {
public:
    InvalidActionException(const string& action) 
        : GameException("잘못된 행동: " + action) {}
};

class GameOverException : public GameException {
public:
    GameOverException() : GameException("게임 오버!") {}
};

// 아이템 클래스
class Item {
private:
    string name;
    int healAmount;
    int attackBonus;

public:
    Item(const string& n, int heal = 0, int attack = 0) 
        : name(n), healAmount(heal), attackBonus(attack) {}

    const string& getName() const { return name; }
    int getHealAmount() const { return healAmount; }
    int getAttackBonus() const { return attackBonus; }

    void use() const {
        cout << name << "을(를) 사용했습니다!" << endl;
    }
};

// 게임 캐릭터 기본 클래스 (추상 클래스)
class Character {
protected:
    string name;
    int health;
    int maxHealth;
    int attack;
    int defense;

public:
    Character(const string& n, int hp, int att, int def) 
        : name(n), health(hp), maxHealth(hp), attack(att), defense(def) {}

    virtual ~Character() = default;

    // 순수 가상 함수
    virtual void displayInfo() const = 0;
    virtual int calculateDamage() const = 0;

    // 공통 기능
    void takeDamage(int damage) {
        int actualDamage = max(1, damage - defense);
        health -= actualDamage;
        cout << name << "이(가) " << actualDamage << " 피해를 받았습니다. ";
        cout << "(체력: " << health << "/" << maxHealth << ")" << endl;
        
        if (health <= 0) {
            health = 0;
            cout << name << "이(가) 쓰러졌습니다!" << endl;
        }
    }

    void heal(int amount) {
        health = min(maxHealth, health + amount);
        cout << name << "이(가) " << amount << " 체력을 회복했습니다. ";
        cout << "(체력: " << health << "/" << maxHealth << ")" << endl;
    }

    bool isAlive() const { return health > 0; }
    const string& getName() const { return name; }
    int getHealth() const { return health; }
    int getMaxHealth() const { return maxHealth; }
    int getAttack() const { return attack; }
};

// 플레이어 클래스
class Player : public Character {
private:
    int experience;
    int level;
    vector<unique_ptr<Item>> inventory;
    int gold;

public:
    Player(const string& n) 
        : Character(n, 100, 20, 5), experience(0), level(1), gold(50) {
        // 기본 아이템 지급
        inventory.push_back(make_unique<Item>("체력 포션", 30, 0));
        inventory.push_back(make_unique<Item>("힘의 물약", 0, 10));
    }

    void displayInfo() const override {
        cout << "\n=== " << name << " 정보 ===" << endl;
        cout << "레벨: " << level << " | 경험치: " << experience << endl;
        cout << "체력: " << health << "/" << maxHealth << endl;
        cout << "공격력: " << attack << " | 방어력: " << defense << endl;
        cout << "골드: " << gold << "G" << endl;
    }

    int calculateDamage() const override {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(attack - 5, attack + 5);
        return max(1, dis(gen));
    }

    void gainExperience(int exp) {
        experience += exp;
        cout << exp << " 경험치를 획득했습니다!" << endl;
        
        // 레벨업 체크
        if (experience >= level * 100) {
            levelUp();
        }
    }

    void gainGold(int amount) {
        gold += amount;
        cout << amount << " 골드를 획득했습니다! (총: " << gold << "G)" << endl;
    }

    void showInventory() const {
        cout << "\n=== 인벤토리 ===" << endl;
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << (i + 1) << ". " << inventory[i]->getName() << endl;
        }
        if (inventory.empty()) {
            cout << "아이템이 없습니다." << endl;
        }
    }

    void useItem(int index) {
        if (index < 1 || index > static_cast<int>(inventory.size())) {
            throw InvalidActionException("잘못된 아이템 번호");
        }

        auto& item = inventory[index - 1];
        item->use();
        
        if (item->getHealAmount() > 0) {
            heal(item->getHealAmount());
        }
        
        if (item->getAttackBonus() > 0) {
            attack += item->getAttackBonus();
            cout << "공격력이 " << item->getAttackBonus() << " 증가했습니다!" << endl;
        }

        // 아이템 사용 후 제거
        inventory.erase(inventory.begin() + index - 1);
    }

    int getGold() const { return gold; }
    int getInventorySize() const { return static_cast<int>(inventory.size()); }

private:
    void levelUp() {
        level++;
        int hpIncrease = 20;
        int attIncrease = 5;
        int defIncrease = 2;
        
        maxHealth += hpIncrease;
        health = maxHealth; // 레벨업 시 체력 완전 회복
        attack += attIncrease;
        defense += defIncrease;
        
        cout << "\n*** 레벨 업! ***" << endl;
        cout << "레벨 " << level << "이 되었습니다!" << endl;
        cout << "체력 +" << hpIncrease << ", 공격력 +" << attIncrease 
             << ", 방어력 +" << defIncrease << endl;
    }
};

// 몬스터 클래스
class Monster : public Character {
private:
    int expReward;
    int goldReward;

public:
    Monster(const string& n, int hp, int att, int def, int exp, int gold) 
        : Character(n, hp, att, def), expReward(exp), goldReward(gold) {}

    void displayInfo() const override {
        cout << "[" << name << "] 체력: " << health << "/" << maxHealth 
             << " | 공격력: " << attack << endl;
    }

    int calculateDamage() const override {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(attack - 3, attack + 3);
        return max(1, dis(gen));
    }

    int getExpReward() const { return expReward; }
    int getGoldReward() const { return goldReward; }
};

// 몬스터 팩토리
class MonsterFactory {
public:
    static unique_ptr<Monster> createRandomMonster(int playerLevel) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 4);
        
        int monsterType = dis(gen);
        int levelMultiplier = max(1, playerLevel);
        
        switch (monsterType) {
            case 1:
                return make_unique<Monster>("슬라임", 
                    30 + levelMultiplier * 10, 
                    8 + levelMultiplier * 2, 
                    1 + levelMultiplier,
                    20 + levelMultiplier * 5,
                    10 + levelMultiplier * 3);
            case 2:
                return make_unique<Monster>("고블린", 
                    50 + levelMultiplier * 15, 
                    12 + levelMultiplier * 3, 
                    3 + levelMultiplier,
                    35 + levelMultiplier * 8,
                    20 + levelMultiplier * 5);
            case 3:
                return make_unique<Monster>("오크", 
                    80 + levelMultiplier * 20, 
                    18 + levelMultiplier * 4, 
                    5 + levelMultiplier * 2,
                    50 + levelMultiplier * 10,
                    35 + levelMultiplier * 7);
            case 4:
                return make_unique<Monster>("드래곤", 
                    150 + levelMultiplier * 30, 
                    25 + levelMultiplier * 5, 
                    8 + levelMultiplier * 3,
                    100 + levelMultiplier * 15,
                    75 + levelMultiplier * 10);
            default:
                return make_unique<Monster>("알 수 없는 몬스터", 40, 10, 2, 25, 15);
        }
    }
};

// 전투 시스템
class BattleSystem {
public:
    static bool battle(Player& player, Monster& monster) {
        cout << "\n=== 전투 시작! ===" << endl;
        cout << player.getName() << " VS " << monster.getName() << endl;
        
        while (player.isAlive() && monster.isAlive()) {
            // 플레이어 턴
            cout << "\n--- 플레이어 턴 ---" << endl;
            cout << "1. 공격  2. 아이템 사용  3. 도망" << endl;
            cout << "선택: ";
            
            int choice;
            cin >> choice;
            
            try {
                switch (choice) {
                    case 1: {
                        int damage = player.calculateDamage();
                        cout << player.getName() << "의 공격!" << endl;
                        monster.takeDamage(damage);
                        break;
                    }
                    case 2: {
                        if (player.getInventorySize() == 0) {
                            cout << "사용할 아이템이 없습니다!" << endl;
                            continue;
                        }
                        player.showInventory();
                        cout << "사용할 아이템 번호: ";
                        int itemIndex;
                        cin >> itemIndex;
                        player.useItem(itemIndex);
                        break;
                    }
                    case 3:
                        cout << "전투에서 도망쳤습니다!" << endl;
                        return false;
                    default:
                        throw InvalidActionException("잘못된 선택");
                }
            }
            catch (const InvalidActionException& e) {
                cout << e.what() << endl;
                continue;
            }
            
            if (!monster.isAlive()) break;
            
            // 몬스터 턴
            cout << "\n--- 몬스터 턴 ---" << endl;
            int damage = monster.calculateDamage();
            cout << monster.getName() << "의 공격!" << endl;
            player.takeDamage(damage);
        }
        
        // 전투 결과
        if (player.isAlive()) {
            cout << "\n*** 승리! ***" << endl;
            player.gainExperience(monster.getExpReward());
            player.gainGold(monster.getGoldReward());
            return true;
        } else {
            throw GameOverException();
        }
    }
};

// 게임 클래스
class Game {
private:
    unique_ptr<Player> player;
    int dungeon_level;
    bool running;

public:
    Game() : dungeon_level(1), running(true) {}

    void initialize() {
        cout << "=== 간단한 RPG 게임 ===" << endl;
        cout << "용사의 이름을 입력하세요: ";
        string playerName;
        cin >> playerName;
        
        player = make_unique<Player>(playerName);
        cout << "\n" << playerName << " 용사여, 모험을 시작합니다!" << endl;
    }

    void run() {
        try {
            while (running && player->isAlive()) {
                showMainMenu();
                handleInput();
            }
        }
        catch (const GameOverException& e) {
            cout << "\n" << e.what() << endl;
            cout << "최종 레벨: " << dungeon_level << endl;
            cout << "게임이 종료되었습니다." << endl;
        }
        catch (const exception& e) {
            cout << "오류 발생: " << e.what() << endl;
        }
    }

private:
    void showMainMenu() {
        cout << "\n=== 메인 메뉴 ===" << endl;
        cout << "던전 레벨: " << dungeon_level << endl;
        cout << "1. 몬스터와 전투" << endl;
        cout << "2. 상태 확인" << endl;
        cout << "3. 인벤토리" << endl;
        cout << "4. 휴식 (체력 회복)" << endl;
        cout << "5. 게임 종료" << endl;
        cout << "선택: ";
    }

    void handleInput() {
        int choice;
        cin >> choice;
        
        try {
            switch (choice) {
                case 1:
                    fight();
                    break;
                case 2:
                    player->displayInfo();
                    break;
                case 3:
                    player->showInventory();
                    break;
                case 4:
                    rest();
                    break;
                case 5:
                    running = false;
                    cout << "게임을 종료합니다." << endl;
                    break;
                default:
                    throw InvalidActionException("잘못된 메뉴 선택");
            }
        }
        catch (const InvalidActionException& e) {
            cout << e.what() << endl;
        }
    }

    void fight() {
        auto monster = MonsterFactory::createRandomMonster(dungeon_level);
        cout << "\n" << monster->getName() << "이(가) 나타났습니다!" << endl;
        monster->displayInfo();
        
        if (BattleSystem::battle(*player, *monster)) {
            dungeon_level++;
            cout << "던전 레벨이 " << dungeon_level << "로 증가했습니다!" << endl;
        }
    }

    void rest() {
        if (player->getGold() >= 20) {
            int healAmount = player->getMaxHealth() - player->getHealth();
            if (healAmount > 0) {
                player->heal(healAmount);
                cout << "20 골드를 지불하고 완전히 회복했습니다." << endl;
                // 골드 차감 로직은 Player 클래스에 추가 필요
            } else {
                cout << "이미 체력이 가득합니다." << endl;
            }
        } else {
            cout << "골드가 부족합니다. (20골드 필요)" << endl;
        }
    }
};

int main() {
    try {
        Game game;
        game.initialize();
        game.run();
    }
    catch (const exception& e) {
        cout << "게임 오류: " << e.what() << endl;
        return 1;
    }
    
    cout << "게임을 플레이해 주셔서 감사합니다!" << endl;
    return 0;
}