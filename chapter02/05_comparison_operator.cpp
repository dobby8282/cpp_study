/* 파일명: 05_comparison_operator.cpp

비교 연산자
    두 값의 크기나 동등성을 비교하여 참(true) 또는 거짓(false)을 반환하는 이항 연산자

    > : 왼쪽 값이 오른쪽 값보다 큰지 비교
    < : 왼쪽 값이 오른쪽 값조다 작은지 비교
    >= : 왼쪽 값이 오른쪽 값보다 크거나 같은지 비교
    <= : 왼쪽 값이 오른쪽 값보다 작거나 같은지 비교
    == : 두 값이 같은지 비교
    != : 두 값이 다른지 비교
*/

#include <iostream>

using namespace std;

int main() {

    int a = 10, b = 20;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a != b: " << (a != b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a >= b: " << (a >= b) << endl;
    cout << "a <= b: " << (a <= b) << endl;

    return 0;
}