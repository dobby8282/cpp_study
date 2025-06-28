/* 
파일명: 04_parameter_by_reference.cpp

참조 전달(Pass by Reference)
    매개변수로 변수의 참조(별명)를 전달하여 원본 변수를 직접 조작하는 방식

    - 참조 매개변수: &를 사용하여 선언된 매개변수로 원본의 별명 역할
    - 원본 변경: 함수 내에서 매개변수 변경 시 원본도 함께 변경됨
    - 메모리 효율성: 복사본을 만들지 않아 메모리와 시간을 절약

*/

#include <iostream>
using namespace std;

void changeByReference(int& x) {
    cout << "함수 내 x 변경 전: " << x << endl;
    x = 100;
    cout << "함수 내 x 변경 후: " << x << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int original = 42;

    cout << "원본 값: " << original << endl;
    changeByReference(original);
    cout << "함수 호출 후 원본: " << original << endl;

    cout << "--- 두 변수 교환 ---" << endl;
    int x = 10, y = 20;
    cout << "교환 전: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "교환 후: x = " << x << ", y = " << y << endl;

    return 0;
}




