/* 파일명: 08_else_if.cpp

다중 조건문
    여러 개의 조건을 순차적으로 검사하여 해당하는 조건에 맞는 코드를 실행하는 제어 구조

    else if: 이전 조건이 거짓일 때 추가 조건을 검사하는 키워드

*/

#include <iostream>

using namespace std;

int main() {

    int score;
    cout << "점수를 입력하세요: ";
    cin >> score;

    if (score >= 90) {
        cout << "A학점" << endl;
    } else if (score >= 80) {
        cout << "B학점" << endl;
    } else if (score >= 70) {
        cout << "C학점" << endl;
    } else if (score >= 50) {
        cout << "D학점" << endl;
    } else {
        cout << "F학점" << endl;
    }
    
    return 0;
}