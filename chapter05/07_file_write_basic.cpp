/*
파일명: 07_file_write_basic.cpp

파일 쓰기 (File Writing)
    ofstream을 사용하여 텍스트 파일에 데이터를 기록하는 기본 방법

    - ofstream: Output File Stream, 파일에 데이터를 쓰기 위한 클래스
    - ios::out: 쓰기 모드 (기본값이므로 생략 가능) 
    - ios::trunc: 파일이 존재하면 내용을 지우고 새로 작성(기본값)
    - open(): 파일을 열기
    - close(): 파일 닫기
    - is_open(): 파일이 제대로 열렸는지 확인

*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    string path =  "/cpp_course/src/chapter05";
    string filename = "output.txt";
    string fullPath = path + "/" + filename;

    ofstream file(fullPath, ios::out | ios::trunc);

    if (file.is_open()) {
        file << "안녕하세요!" << endl;
        file << "파일 쓰기 테스트 입니다.111" << endl;
        file << "숫자: " << 123 << endl;

        cout << "파일 쓰기 완료: output.txt" << endl;
    } else {
        cout << "파일 열기 실패!" << endl;
    }

    return 0;
}

