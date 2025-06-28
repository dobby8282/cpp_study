/*
 * 파일명: 09_lambda_stl_algorithm.cpp
 * 
 * 주제: 람다와 STL 알고리즘 (Lambda with STL Algorithms)
 * 정의: 람다 표현식을 STL 알고리즘과 함께 사용하여 유연한 데이터 처리 구현
 * 
 * 핵심 개념:
 * - 람다를 조건자(predicate), 변환자(transformer), 비교자(comparator)로 활용
 * - STL 알고리즘에 맞춤형 로직을 쉽게 전달 가능
 * - 함수형 프로그래밍(map, filter, reduce)에 적합
 * 
 * 함수형 프로그래밍 패턴:
 * - Map: transform으로 각 요소를 변환
 * - Filter: remove_if, copy_if로 조건에 맞는 요소 선별
 * - Reduce: accumulate, for_each로 요소들을 하나의 값으로 축약
 * - Find: find_if로 조건에 맞는 요소 검색
 * 
 */

#include <iostream>      // 표준 입출력
#include <vector>        // vector 컨테이너
#include <algorithm>     // find_if, count_if, sort, for_each 등
#include <string>        // string 클래스
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "=== find_if: 조건 검색 ===" << endl;

    // 조건을 만족하는 첫 번째 요소 검색 (짝수)
    auto it = find_if(numbers.begin(), numbers.end(), [](int n) {
        return n % 2 == 0;  // 조건: 짝수인지 확인
    });

    if (it != numbers.end()) {
        cout << "첫 번째 짝수: " << *it << endl;
    }

    cout << "\n=== count_if: 조건 계산 ===" << endl;

    // 조건을 만족하는 요소 개수 세기 (5보다 큰 수)
    int count = count_if(numbers.begin(), numbers.end(), [](int n) {
        return n > 5;
    });
    cout << "5보다 큰 수의 개수: " << count << endl;

    cout << "\n=== sort: 정렬 기준 ===" << endl;

    vector<string> words = {"banana", "apple", "cherry", "date"};

    // 사용자 정의 정렬 기준 (문자열 길이 기준 오름차순 정렬)
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    cout << "길이 순 정렬: ";
    for (const string& word : words) {
        cout << word << " ";
    }
    cout << endl;

    cout << "\n=== for_each: 캡처 사용 ===" << endl;

    int sum = 0;

    // 모든 요소에 대해 sum에 누적 (람다에서 외부 변수 참조 캡처)
    for_each(numbers.begin(), numbers.end(), [&sum](int n) {
        sum += n;
    });

    cout << "총합: " << sum << endl;

    return 0;
}
