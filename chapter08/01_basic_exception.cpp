/*
 * 파일명: 01_basic_exception.cpp
 * 
 * 주제: 기본 예외 처리 (Basic Exception Handling)
 * 정의: try-catch 구문을 사용하여 런타임 오류를 안전하게 처리
 * 
 * 핵심 개념:
 * - try 블록: 예외가 발생할 수 있는 코드를 감싸는 영역
 * - catch 블록: 특정 예외 타입을 받아 처리
 * - throw 문: 오류 발생 시 예외 객체를 던짐
 * - 표준 예외 클래스 사용: invalid_argument, out_of_range 등
 */

#include <iostream>       // 표준 입출력
#include <stdexcept>      // 표준 예외 클래스들
using namespace std;

// 나눗셈 함수: 0으로 나눌 경우 예외 발생
double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("0으로 나눌 수 없습니다!");
    }
    return a / b;
}

// 배열 요소 접근 함수: 인덱스가 유효하지 않으면 예외 발생
int getArrayElement(int arr[], int size, int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("배열 인덱스가 범위를 벗어났습니다!");
    }
    return arr[index];
}

int main() {
    cout << "=== 기본 예외 처리 ===" << endl;

    // 1. 나눗셈 예외 처리
    try {
        cout << "10 / 2 = " << divide(10, 2) << endl;
        cout << "10 / 0 = " << divide(10, 0) << endl;  // 예외 발생
    }
    catch (const invalid_argument& e) {
        // divide()에서 invalid_argument 발생 시 처리
        cout << "오류 발생: " << e.what() << endl;
    }

    // 2. 배열 인덱스 접근 예외 처리
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;

    try {
        cout << "\n배열[2] = " << getArrayElement(numbers, size, 2) << endl;
        cout << "배열[10] = " << getArrayElement(numbers, size, 10) << endl;  // 예외 발생
    }
    catch (const out_of_range& e) {
        // getArrayElement()에서 out_of_range 발생 시 처리
        cout << "배열 오류: " << e.what() << endl;
    }

    // 3. 다중 예외 처리 (순서 중요)
    try {
        cout << "\n5 / 1 = " << divide(5, 1) << endl;
        cout << "배열[0] = " << getArrayElement(numbers, size, 0) << endl;
        cout << "3 / 0 = " << divide(3, 0) << endl;  // 예외 발생
    }
    catch (const invalid_argument& e) {
        cout << "나누기 오류: " << e.what() << endl;
    }
    catch (const out_of_range& e) {
        cout << "범위 오류: " << e.what() << endl;
    }
    catch (...) {
        // 알 수 없는 예외 처리
        cout << "알 수 없는 오류가 발생했습니다." << endl;
    }

    cout << "\n프로그램이 정상적으로 계속됩니다." << endl;
    return 0;
}
