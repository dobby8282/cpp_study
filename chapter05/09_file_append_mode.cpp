/* 
파일명: 09_file_append_mode.cpp

파일 추가 모드 (Append Mode)
    기존 파일의 끝에 새로운 내용을 추가하는 방법

    - ios::app: Append 모드, 파일 끝에 내용 추가
    - 기존파일 내용을 지우지 않음
    - 파일이 없으면 자동 생성
*/
#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string path =  "/cpp_course/src/chapter05";
    string filename = "log.txt";
    string fullPath = path + "/" + filename;

    // 첫 번째: 기본 파일 생성
    ofstream createFile(fullPath);  // ios::out | ios::trunc 생략
    createFile << "=== 로그 시작 ===" << endl;
    createFile << "첫 번째 로그 항목" << endl;
    createFile.close();

    // 두 번째: 추가 모드로 내용 추가
    ofstream appendFile(fullPath, ios::app);

    if (appendFile.is_open()) {
        appendFile << "두 번째 로그 항목" << endl;
        appendFile << "세 번째 로그 항목" << endl;
        appendFile << "=== 로그 종료 ===" << endl;

        cout << "로그 파일에 내용 추가 완료" << endl;
        appendFile.close();

    }

    return 0;
}
