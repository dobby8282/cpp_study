/*
파일명: 06_function_overloading.cpp

함수 오버로딩(Function Overloading)
    같은 이름의 함수를 매개변수의 개수나 타입을 다르게 하여 여러 개 정의하는 기능

*/

#include <iostream>
using namespace std;

// 정수 덧셈
int add(int a, int b) {
    return a + b;
}

// 실수 덧셈
double add(double a, double b) {
    return a + b;
}

// 세 개 정수 덧셈
int add(int a, int b, int c) {
    return a + b + c;
}

int main() {

    cout << add(3, 4) << endl;
    cout << add(3.5, 4.2) << endl;
    cout << add (1, 2, 3) << endl;

    return 0;
}

