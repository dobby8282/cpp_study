/* 파일명: 03_arithmetic_operator.cpp

연산자
    변수나 값에 대해 특정한 연상을 수행하는 기호

산술 연산자
    +, -, *(곱하기), /(나누기), %(나눈 나머지)

*/

#include <iostream>

using namespace std;

int main() {

    int a = 10, b = 3;

    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;
    cout << "a % b = " << (a % b) << endl;

    // 실수 나눗셈
    double result = static_cast<double>(a) / b;
    cout << "a / b = " << result << "(실수 나눗셈)" << endl;



    return 0;
}

