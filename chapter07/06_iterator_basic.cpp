/*
 * 파일명: 06_iterator_basic.cpp
 * 
 * 주제: 반복자 기초 (Iterator Basics)
 * 정의: 컨테이너의 요소들을 순차적으로 접근하는 객체
 * 
 * 핵심 개념:
 * - 반복자: 포인터처럼 동작하며, 다양한 컨테이너를 동일하게 순회 가능
 * - begin()/end(): 시작과 끝(마지막 요소의 다음) 위치
 * - rbegin()/rend(): 역방향 반복자
 * - auto: 반복자 타입 자동 추론 (C++11부터)
 * 
 * 반복자 카테고리:
 * - Input, Output, Forward, Bidirectional, Random Access 등
 * 
 * 장점:
 * - 컨테이너 독립적 순회 가능
 * - STL 알고리즘과 호환성 뛰어남
 * - 요소 수정, 조건부 순회 등 유연한 제어
 */

#include <iostream>   // 표준 입출력
#include <vector>     // vector 컨테이너
#include <list>       // list 컨테이너
#include <map>        // map 컨테이너
using namespace std;

int main() {
    cout << "=== vector 반복자 ===" << endl;
    vector<int> numbers = {10, 20, 30, 40, 50};

    // begin(): 첫 요소 반복자, end(): 마지막 요소의 다음 위치 반복자
    cout << "numbers.begin(): " << *numbers.begin() << endl;
    // end()는 마지막 요소가 아니라 그 다음을 가리키므로 역참조하면 위험 → 주석 처리
    // cout << "numbers.end(): " << *numbers.end() << endl;

    // 순방향 반복자 사용
    cout << "순방향: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 역방향 반복자 사용
    cout << "역방향: ";
    for (vector<int>::reverse_iterator it = numbers.rbegin(); it != numbers.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // auto 키워드로 반복자 타입 생략 (C++11 이상)
    cout << "auto 사용: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n=== list 반복자 ===" << endl;
    list<string> words = {"hello", "world", "STL"};

    // list는 bidirectional iterator를 사용 (양방향 순회 가능)
    for (auto it = words.begin(); it != words.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "\n=== map 반복자 ===" << endl;
    map<string, int> ages = {
        {"김철수", 25},
        {"이영희", 23},
        {"박민수", 27}
    };

    // map의 반복자는 pair<const Key, T>를 가리킴 → ->first, ->second로 접근
    for (auto it = ages.begin(); it != ages.end(); ++it) {
        cout << it->first << ": " << it->second << "세" << endl;
    }

    cout << "\n=== 반복자로 요소 수정 ===" << endl;
    // 반복자를 사용하여 vector 요소 수정
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        *it *= 2;  // 요소 값 2배 증가
    }

    // 수정된 vector 출력
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
