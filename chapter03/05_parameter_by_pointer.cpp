/* 
파일명: 05_parameter_by_pointer.cpp

포인터 전달 (Pass by Pointer)
    매개변수로 변수의 주소를 전달하여 간접적으로 원본 변수에 접근하는 방식

    - 포인터 매개변수: *를 사용하여 선언된 매개변수로 주소값을 받음
    - 역참조: *연산자를 사용하여 포인터가 가리키는 값에 접근
    - 주소 전달: &연산자로 변수의 주소를 함수에 전달

*/

#include <iostream>
using namespace std;

void changeByPointer(int* x) {
    cout << "함수 내 *x 변경 전: " << *x << endl;
    *x = 100;

    cout << "함수 내 *x 변경 후: " << *x << endl;
}

void multiply(int* a, int* b, int* result) {
    *result = (*a) * (*b);
}

int main() {
    int  original = 42;

    cout << "원본 값: " << original << endl;
    changeByPointer(&original);
    cout << "함수 호출 후 원본: " << original << endl;

    cout << "--- 곱셈 결과 ---" << endl;
    int num1 = 6, num2 = 7, product;
    multiply(&num1, &num2, &product);
    cout << num1 << " x " << num2 << " = " << product << endl;

    return 0;
}