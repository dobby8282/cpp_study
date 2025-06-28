/*
 * 파일명: 08_lambda_basic.cpp
 * 
 * 주제: 람다 표현식 기초 (Lambda Expression Basics)
 * 정의: 익명 함수를 생성하는 C++11의 기능
 * 
 * 핵심 개념:
 * - 람다: 이름 없는 함수, 즉석에서 정의하고 사용
 * - 캡처 절: 람다 내부에서 외부 변수를 사용하는 방법
 * - 함수 객체: 람다는 내부적으로 함수 객체(클래스)로 변환됨
 * - 클로저: 람다가 생성한 함수 객체 인스턴스를 의미
 * 
 * 장점:
 * - 간결하고 지역적인 코드 작성 가능
 * - STL 알고리즘과 자연스럽게 결합
 * - 함수 포인터보다 안전하고 유연함
 */

#include <iostream>      // 표준 입출력
#include <vector>        // vector 컨테이너
#include <algorithm>     // for_each 등 알고리즘
#include <functional>    // std::function 등 (재귀 시 사용)
using namespace std;

int main() {
    cout << "=== 기본 람다 ===" << endl;

    // 1. 기본 형태의 람다 (매개변수 없음)
    auto hello = []() {
        cout << "Hello Lambda!" << endl;
    };
    hello();  // 호출

    // 2. 매개변수를 받는 람다
    auto add = [](int a, int b) {
        return a + b;
    };
    cout << "5 + 3 = " << add(5, 3) << endl;

    // 3. 반환 타입을 명시한 람다
    auto divide = [](double a, double b) -> double {
        return b != 0 ? a / b : 0;
    };
    cout << "10.0 / 3.0 = " << divide(10.0, 3.0) << endl;

    cout << "\n=== 캡처 절 ===" << endl;

    int x = 10;
    int y = 20;

    // 1. 값으로 캡처 (복사, 읽기 전용)
    auto lambda1 = [x, y]() {
        cout << "값 캡처: x=" << x << ", y=" << y << endl;
    };

    // 2. 참조로 캡처 (원본 변수에 직접 접근 가능)
    auto lambda2 = [&x, &y]() {
        x += 5;
        y += 10;
        cout << "참조 캡처 후: x=" << x << ", y=" << y << endl;
    };

    // 3. 모든 변수 값으로 캡처
    auto lambda3 = [=]() {
        cout << "모든 변수 값 캡처: x=" << x << ", y=" << y << endl;
    };

    lambda1();
    lambda2();
    lambda3();

    cout << "\n=== STL과 함께 사용 ===" << endl;

    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 짝수만 출력 (for_each + 람다)
    cout << "짝수: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        if (n % 2 == 0) cout << n << " ";
    });
    cout << endl;

    return 0;
}
