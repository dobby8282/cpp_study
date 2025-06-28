/*
 * 파일명: 04_vector_basic.cpp
 * 
  * STL (Standard Template Library)
= C++ 표준 템플릿 라이브러리
= 자료구조 + 알고리즘 + 반복자를 모아놓은 강력한 표준 라이브러리
 * 
 * 주제: vector 기초 (Vector Basics)
 * 정의: 동적 배열을 제공하는 STL 컨테이너
 * 
 * 핵심 개념:
 * - 동적 배열: 실행 시간에 크기를 변경할 수 있는 배열
 * - 자동 메모리 관리: new/delete 없이 자동으로 메모리 할당/해제
 * - 연속 메모리: 요소들이 메모리에 연속적으로 저장됨
 * - 랜덤 액세스: 인덱스로 O(1) 시간에 임의 요소 접근 가능
 * 
 * 주요 멤버 함수:
 * - push_back(): 끝에 요소 추가
 * - pop_back(): 끝에서 요소 제거
 * - size(): 현재 요소 개수 반환
 * - empty(): 비어있는지 확인
 * - front()/back(): 첫/마지막 요소 접근
 * - at(): 범위 검사를 포함한 요소 접근
 * 
 * vector vs 배열:
 * - 크기: vector는 동적, 배열은 고정
 * - 메모리 관리: vector는 자동, 배열은 수동
 * - 안전성: vector는 범위 검사 옵션, 배열은 없음
 * - 기능: vector는 많은 멤버 함수, 배열은 기본적
 * 
 */

#include <iostream>      // 표준 입출력 사용을 위한 헤더
#include <vector>        // vector STL 사용을 위한 헤더
#include <string>        // string 클래스 사용을 위한 헤더
using namespace std;

int main() {
    // vector 생성과 초기화
    vector<int> numbers;  // 빈 정수 벡터 생성
    vector<int> scores = {90, 85, 92, 78, 96};  // 초기값을 가진 정수 벡터
    vector<string> names(3, "unknown");  // "unknown"으로 초기화된 문자열 3개 저장

    cout << "=== 요소 추가 ===" << endl;
    numbers.push_back(10);  // 10 추가
    numbers.push_back(20);  // 20 추가
    numbers.push_back(30);  // 30 추가

    cout << "numbers 크기: " << numbers.size() << endl;  // 현재 크기 출력

    cout << "\n=== 요소 접근 ===" << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << "numbers[" << i << "] = " << numbers[i] << endl;  // 인덱스를 이용한 요소 출력
    }

    cout << "\n=== range-based for loop ===" << endl;
    for (int score : scores) {  // 범위 기반 for 문으로 모든 요소 출력
        cout << score << " ";
    }
    cout << endl;

    cout << "\n=== 요소 수정 ===" << endl;
    scores[0] = 95;       // 첫 번째 요소 값을 95로 수정
    scores.at(1) = 88;    // 두 번째 요소 값을 88로 수정 (at()은 범위 체크 포함)

    cout << "\n=== 요소 삭제 ===" << endl;
    cout << "삭제 전 크기: " << scores.size() << endl;
    scores.pop_back();  // 마지막 요소 삭제
    cout << "삭제 후 크기: " << scores.size() << endl;

    cout << "\n=== vector 정보 ===" << endl;
    cout << "비어있는가? " << (numbers.empty() ? "예" : "아니오") << endl;  // 비어 있는지 확인
    cout << "첫 번째 요소: " << numbers.front() << endl;  // 첫 번째 요소 출력
    cout << "마지막 요소: " << numbers.back() << endl;    // 마지막 요소 출력

    return 0;
}
