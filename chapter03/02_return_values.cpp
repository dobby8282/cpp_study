/*
파일명: 02_return_values.cpp

함수 반환값 (Function Return Value)
    함수가 작업을 완료한 후 호출자에게 돌려주는 결과값

    void 함수: 반환값이 없는 함수
*/

#include <iostream>
using namespace std;

// 반환값이 있는 함수
double calculateArea(double radius) {
    return 3.14159 * radius * radius;
}

// 반환값이 없는 함수
void printResult(double area) {
    cout << "원의 넓이: " << area << endl;
}

// bool 반환 함수
bool isEven(int number) {
    return number % 2 == 0;
}

int main() {

    double radius = 5.0;
    double area = calculateArea(radius);

    printResult(area);

    int num = 8;
    if (isEven(num)) {
        cout << num << "은 짝수입니다." << endl;
    }

    return 0;
}
