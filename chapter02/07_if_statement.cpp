/* 파일명: 07_if_statement.cpp

조건문
    주어진 조건의 참/거짓에 따라 프로그램의 실행 흐름을 분기하는 제어 구조

    if: 조건이 참일 때 특정 코드 블록을 실행하는 키워드
    else: if 조건이 거짓일 때 실행할 대안 코드 블록을 지정하는 키워드

삼항연산자 
    조건식 ? 조건식이 참일때 반환값 : 조건식이 거짓일때 반환값

*/

#include <iostream>

using namespace std;

int main() {

    int score;
    cout << "점수를 입력하세요: ";
    cin >> score;

    // 단순 if-else
    if(score >= 60) {
        cout << "합격!" << endl;
    } else {
        cout << "불합격..." << endl;
    }

    // 삼항 연산자
    string result = (score >= 60) ? "합격" : "불합격";
    cout << "결과: " << result << endl;

    return 0;
}



