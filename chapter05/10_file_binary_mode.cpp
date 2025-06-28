/*
파일명: 10_file_binary_mode.cpp

바이너리 파일 처리 (Binary File Handling)
    텍스트가 아닌 바이너리 데이터를 파일에 저장하고 읽는 방법

    - ios::binary: 바이너리 모드로 파일 열기
    - write(): 바이너리 데이터 쓰기
    - read(): 바이너리 데이터 읽기
    - sizeof(): 데이터 크기 계산
    - reinterpet_cast: 포인터 타입 변환
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Player {
    char name[20];
    int level;
    float health;
    int score;
};

int main() {

    string path =  "/cpp_course/src/chapter05";
    string filename = "player.dat";
    string fullPath = path + "/" + filename;

    Player player = {"홍길동", 25, 85.5f, 12000};

    // 바이너리 쓰기 모드
    ofstream outFile(fullPath, ios::binary);
    if (outFile.is_open()) {
        outFile.write(reinterpret_cast<char*>(&player), sizeof(Player));
        outFile.close();
        cout << "플레이어 데이터 저장 완료" << endl;
    }

    Player loadedPlayer;
    
    // 바이너리 읽기 모드
    ifstream inFile(fullPath, ios::binary);

    if (inFile.is_open()) {
        inFile.read(reinterpret_cast<char*>(&loadedPlayer), sizeof(Player));
        inFile.close();

        cout << "\n=== 불러온 플레이어 정보 ===" << endl;
        cout << "이름: " << loadedPlayer.name <<  endl;
        cout << "레벨: " << loadedPlayer.level <<  endl;
        cout << "체력: " << loadedPlayer.health <<  endl;
        cout << "점수: " << loadedPlayer.score <<  endl;
    }

    return 0;
}