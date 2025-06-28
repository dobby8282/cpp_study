/* 파일명: 06_logical_operator.cpp

논리 연산자
    논리값(true/false)들을 조합하여 복합적인 조건을 만드는 연산자

    &&(논리 AND): 두 조건이 모두 참일 때 참 반환
    ||(논리 OR): 두 조건 중 하나라도 참이면 참
    !(논리 NOT): 논리값을 반대로 바꾸는 단항 연산자


*/

#include <iostream>

using namespace std;

int main() {

    bool a = true, b = false;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a && b: " << (a && b) << endl;
    cout << "a || b: " << (a || b) << endl;
    cout << "!a:" << (!a) << endl;

    
    int age = 25;
    bool hasLicense = true;

    if (age >= 18 && hasLicense) {
        cout << "운전 가능" << endl;
    } else {
        cout << "운전 불가능" << endl;
    }

    return 0;
}












