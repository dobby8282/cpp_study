/* 파일명: 13_break_conitnue.cpp

break 문
    현재 반복문을 즉시 종료하는 키워드

continue
    현재 반복믜 나머지 부분을 건너뛰고 다음 반복으로 이동하는 키워드

*/

#include <iostream>

using namespace std;

int main() {

    // continue - 홀수만 출력
    cout << "1부터 10까지 홀수만: " << endl;
    for(int i = 1; i <= 10; i++) {
        if(i % 2 == 0) {    // 짝수명 건너뛰기
            continue;
        }

        cout << i << " ";

    }
    cout << endl;

    // break - 5에서 중단
    cout << "1부터 시작해서 5에서 중단: " << endl;
    for(int i = 1; i <= 10; i++){
        if(i == 5) break;

        cout << i << " ";
    }

    cout << endl;

    return 0;
}
