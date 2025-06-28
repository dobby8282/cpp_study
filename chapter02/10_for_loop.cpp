/* 파일명: 10_for_loop.cpp

반복문 
    특정 조건이 만족되는 동안 코드 블록을
    반복적으로 실행하는 제어 구조

    for(초기화; 조건식; 증감식) {
        반복 실행 코드
    }

    초기화: 반복 시작 전 변수를 설정하는 부분
    조건: 반복을 계속할지 결정하는 논리 표현식
    증감: 각 반복 후 제어 변수를 변경하는 부분

*/

#include <iostream>

using namespace std;

int main() {

    // 기본 for문
    cout << "1부터 5까지:" << endl;
    for(int i = 1; i <= 5; i++) {
        cout << i << " ";
    }

    cout << endl;

    // 구구단
    int dan = 3;
    cout << dan << "단:" << endl;
    for(int i = 1; i <= 9; i++) {
        cout << dan << " x " << i << " = " << (dan * i) << endl;
    }


    return 0;
}