/*
파일명: 01_function_template.cpp

함수 템플릿 (Funtion Template)
    타입에 독립적인 일반화된 함수를 작성하는 기법
    다양한 타입에 대해 동일한 로직을 적용하는 함수
*/

#include <iostream>
using namespace std;

// 함수 템플릿
template<typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T, typename U>
void printPair(T first, U second) {
    cout << "(" << first << ", " << second << ")" 
    << endl;
}

int main() {

    // 정수형
    cout << "최대값: " << getMax(10, 20) << endl;
    // 실수형
    cout << "최대값: " << getMax(3.5, 2.8) << endl;

    // swap 테스트
    int x = 5, y = 10;
    mySwap(x, y);
    cout << "swap 후: x = " << x 
    << ", y = " << y << endl;

    printPair(42, "hello");


    return 0;
}