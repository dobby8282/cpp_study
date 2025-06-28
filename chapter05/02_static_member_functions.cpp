/* 
파일명: 02_static_member_functions.cpp 
*/

#include <iostream>
using namespace std;

class Card{

private :
    // 일반 멤버 변수
    string suit;    // 모양
    int number;     // 번호

    // 정적 멤버 변수
    static int width;   // 가로 길이
    static int height;  // 세로 길이
    static int totalCards;  // 생성된 카드 개수


public :

    Card(string s, int n) : suit(s), number(n) {
        totalCards++;
        cout << suit << number << " 카드 생성! (총 " << totalCards << "장)" << endl;
    }

    ~Card() {
        totalCards--;
        cout << suit << number << " 카드 삭제" << endl;
    }

    // 정적 함수 (객체 없이 호출 가능)
    static void showCardSize() {
        cout << "카드 크기: " << width << "cm x " << height << "cm" << endl;
    }

    static int getTotalCards() {
        return totalCards;
    }

    void display() {
        cout << "카드: " << suit << number << " (크기: "
         << width << "x" << height << ")" << endl;
    }
};

// 정적 멤버 변수 초기화 (클래스 외부에서 필수!)
int Card::width = 6;
int Card::height = 9;
int Card::totalCards = 0;

int main() {
    
    cout << "=== 카드 게임 시작 ===" << endl;
    
    // 객체 생성 전에도 정적 멤버 사용 가능
    Card::showCardSize();
    cout << "현재 카드: " << Card::getTotalCards() << "장" << endl;

    cout << "\n--- 카드 생성 ---" << endl;
    Card card1("♠", 1);        // 스페이드 A
    Card card2("♥", 13);       // 하트 K
    Card card3("◆", 7);       // 다이아몬드 7



    cout << "\n--- 카드 정보 ---" << endl;
    card1.display();
    card2.display();
    card3.display();

    cout << "\n--- 카드 현황 ---" << endl;
    cout << "총 카드 수: " << Card::getTotalCards() << "장" << endl;
    Card::showCardSize();


    return 0;
}
