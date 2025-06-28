/* 
파일명: 08_file_read_basic.cpp

파일 읽기 (File Reading)
    ifstream을 사용하여 텍스 파일에서 데이터를 읽어오는 기본 방법

    - ifstream: Input File Stream, 파일에서 데이터를 읽기 위한 클래스
    - ios::in: 읽기 모드 (기본값이므로 생략 가능)
    - getline(): 한 줄씩 읽기
    
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string path =  "/cpp_course/src/chapter05";
    string filename = "output.txt";
    string fullPath = path + "/" + filename;

    ifstream file(fullPath);
    string line;

    if (file.is_open()) {
        cout << "=== 파일 내용 ===\n";

        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
        cout << "파일 읽기 완료" << endl;

    } else {
        cout << "파일 열기 실패! output.txt 가 존재하는지 확인하세요." << endl;
    }

    return 0;
}