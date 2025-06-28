/*
파일명: 03_parameter_by_value.cpp

매개변수 전달 방식 - 값 전달
    인수의 값을 복상하여 매개변수에 전달하는 방식
    원본과 별개의 메모리에 저장된 값의 사본
    함수 내에서 매개변수를 변경해도 원본은 영향받지 않음    

*/

#include <iostream>
using namespace std;

void changeValue(int x) {   // int x = 42;
    cout << "함수 내 x 변경 전: " << x << endl;
    x = 100;
    cout << "함수 내 x 변경 후: " << x << endl;
    
}

void doubleValue(int num) {
    num = num * 2;
    cout << "함수 내에서 두 배: " << num << endl;
}

int main() {
    int original = 42;

    cout << "원본 값: " << original << endl;
    changeValue(original);
    cout << "함수 호출 후 원본: " << original << endl;

    cout << "--- 또 다른 예제 ---" << endl;
    int number = 5;
    cout << "원본 값: " << number << endl;
    doubleValue(number);
    cout << "함수 호출 후 원본: " << number << endl;


    return 0;
}
