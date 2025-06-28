/*
 * 파일명: 08_stl_algorithm_basic.cpp
 * 
 * 주제: STL 알고리즘 기초 (STL Algorithm Basics)
 * 정의: 반복자 기반으로 다양한 컨테이너에 적용 가능한 알고리즘 함수들
 * 
 * 핵심 개념:
 * - 알고리즘은 컨테이너와 분리되어 반복자만으로 동작
 * - 제네릭, 함수형 프로그래밍 스타일 지향
 * - 변경/비변경/수치/집합 알고리즘으로 분류됨
 */

#include <iostream>      // 표준 입출력
#include <vector>        // vector 컨테이너
#include <algorithm>     // sort, find, replace 등 STL 알고리즘
#include <numeric>       // accumulate, 수치 연산 알고리즘
using namespace std;

int main() {
    vector<int> numbers = {5, 2, 8, 1, 9, 3};  // 초기 데이터

    // 원본 출력
    cout << "원본: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "\n=== 정렬 알고리즘 ===" << endl;

    // 오름차순 정렬 (기본 정렬)
    sort(numbers.begin(), numbers.end());
    cout << "오름차순: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // 내림차순 정렬 (greater<int> 함수 객체 사용)
    /*
        int 타입에 대해 **"왼쪽 > 오른쪽"**인지 비교하는 함수 객체
        sort() 같은 알고리즘에서 정렬 기준으로 사용됨
        greater<int>()(a, b) 는 a > b 와 같은 의미
    */
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "내림차순: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    cout << "\n=== 검색 알고리즘 ===" << endl;

    // 이진 검색을 위한 오름차순 정렬
    sort(numbers.begin(), numbers.end());

    int target = 5;
    if (binary_search(numbers.begin(), numbers.end(), target)) {
        cout << target << "을(를) 찾았습니다." << endl;
    }

    // 선형 검색 (find)
    auto it = find(numbers.begin(), numbers.end(), 8);
    if (it != numbers.end()) {
        // 반복자의 위치 계산
        cout << "8의 위치: " << distance(numbers.begin(), it) << endl;
    }

    cout << "\n=== 수치 알고리즘 ===" << endl;

    // 합계 계산 (초기값 0)
    int sum = accumulate(numbers.begin(), numbers.end(), 0);
    cout << "합계: " << sum << endl;

    // 최댓값, 최솟값
    int maxVal = *max_element(numbers.begin(), numbers.end());
    int minVal = *min_element(numbers.begin(), numbers.end());
    cout << "최댓값: " << maxVal << ", 최솟값: " << minVal << endl;

    cout << "\n=== 변경 알고리즘 ===" << endl;

    // 특정 값 대체 (5 → 50)
    replace(numbers.begin(), numbers.end(), 5, 50);
    cout << "5를 50으로 변경: ";
    for (int n : numbers) cout << n << " ";
    cout << endl;

    return 0;
}
