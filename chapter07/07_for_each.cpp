/*
 * 파일명: 07_for_each.cpp
 * 
 * 주제: C++ 반복문 비교 (Loop Comparison in C++)
 * 정의: for_each, range-based for, 일반 for문의 특징과 사용법 비교
 * 
 * 핵심 개념:
 * - for_each: 함수형 스타일의 순회, 람다/함수 객체와 사용
 * - range-based for: C++11의 간결한 문법, 안전하고 직관적
 * - 일반 for문: 인덱스를 활용한 세밀한 제어 가능
 */

#include <iostream>     // 입출력
#include <vector>       // vector 사용
#include <algorithm>    // for_each 사용
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};

    cout << "=== 기본 출력 ===" << endl;

    // 1. for_each 사용 (람다 함수 사용)
    cout << "for_each: ";
    for_each(numbers.begin(), numbers.end(), [](int n) {
        cout << n << " ";
    });
    cout << endl;

    // 2. range-based for 사용 (C++11 이후)
    cout << "range-based for: ";
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    // 3. 일반 for문 (전통적 방식, 인덱스 사용 가능)
    cout << "일반 for문: ";
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << "\n=== 요소 수정 (각 요소를 2배로) ===" << endl;


    // 보류
    // 1. for_each를 통한 요소 수정 (참조로 받아야 함)
    vector<int> data1 = {1, 2, 3, 4, 5};
    for_each(data1.begin(), data1.end(), [](int& n) { n *= 2; });
    cout << "for_each 결과: ";
    for (int n : data1) cout << n << " ";
    cout << endl;

    // 2. range-based for 참조 사용
    vector<int> data2 = {1, 2, 3, 4, 5};
    for (int& n : data2) { n *= 2; }
    cout << "range-based for 결과: ";
    for (int n : data2) cout << n << " ";
    cout << endl;

    // 3. 일반 for문 인덱스를 통한 직접 수정
    vector<int> data3 = {1, 2, 3, 4, 5};
    for (int i = 0; i < data3.size(); i++) { data3[i] *= 2; }
    cout << "일반 for문 결과: ";
    for (int n : data3) cout << n << " ";
    cout << endl;

    cout << "\n=== 인덱스가 필요한 경우 ===" << endl;
    vector<string> fruits = {"사과", "바나나", "체리"};

    // for_each에서는 외부 변수로 인덱스 추적 필요
    int index = 0;
    for_each(fruits.begin(), fruits.end(), [&index](const string& fruit) {
        cout << index++ << ":" << fruit << " ";
    });
    cout << endl;

    // 일반 for문에서는 인덱스 활용 쉬움
    for (int i = 0; i < fruits.size(); i++) {
        cout << i << ":" << fruits[i] << " ";
    }
    cout << endl;

    cout << "\n=== 결론 ===" << endl;
    cout << "• for_each: 함수형 프로그래밍 스타일" << endl;
    cout << "• range-based for: 가장 간단하고 안전" << endl;
    cout << "• 일반 for문: 인덱스 필요시 사용" << endl;

    return 0;
}
