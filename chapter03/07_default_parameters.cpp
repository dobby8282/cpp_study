/* 
파일명: 07_default_parameters.cpp

디폴트 매개변수 (Default Parameters)
    함수 선언 시 매개변수에 기본값을 설정하여, 호출 시 인수가 생략되면 기본값을 사용하는 기능

    디폴트 매개변수는 매개변수 목록의 오른쪽부터 설정해야 함
*/

#include <iostream>
using namespace std;

// 디폴트 매개변수가 있는 함수
void printMessage(string message, int count = 1, char separator = '-') {
    for(int i = 0; i < count; i++) {
        cout << message;
        if(i < count - 1) {
            cout << separator;
        }

    }
    cout << endl;
}

// 원의 넓이 계산 (pi 값 디폴트)
double calculateCircleArea(double radius, double pi = 3.141592) {
    return pi * radius * radius;
}

int main() {


    // 다양한 방식으로 함수 호출
    printMessage("Hello");      // count=1, separator ='-'
    printMessage("Hi", 3);      // separator ='-'
    printMessage("Test", 2, '*');

    cout << "\n 원의 넓이: " << endl;
    cout << "반지름 5 (기본 pi): " << calculateCircleArea(5) << endl;
    cout << "반지름 5 (정확한 pi): " << calculateCircleArea(5, 3.141592653589793) << endl;


    return 0;
}




