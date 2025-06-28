/*
 * 파일명: 05_list_map_basic.cpp
 * 
 * 주제: list와 map 기초 (List & Map Basics)
 * 정의: 연결 리스트와 키-값 쌍을 관리하는 STL 컨테이너
 * 
 * 핵심 개념:
 * - list: 이중 연결 리스트 구조의 순차 컨테이너
 * - map: 키-값 쌍을 저장하는 연관 컨테이너 (자동 정렬)
 * 
 * 특징:
 * - list: 중간 삽입/삭제 O(1), 순차 접근만 가능
 * - map: 키 기준 정렬, 중복 키 불가, O(log n) 검색/삽입/삭제
 * 
 * 주요 함수:
 * - list: push_front/back, pop_front/back, insert, erase
 * - map: insert, find, count, erase, operator[]
 * 
 * 관련 컨테이너:
 * - vector vs list, map vs unordered_map, set, multimap 등
 */

#include <iostream>  // 표준 입출력
#include <list>      // STL list 사용
#include <map>       // STL map 사용
#include <string>    // string 클래스 사용
using namespace std;

int main() {
    cout << "=== list 기초 ===" << endl;

    list<string> todoList;  // string을 저장하는 list 선언

    // 요소 추가
    todoList.push_back("숙제하기");     // 맨 뒤에 추가
    todoList.push_front("일어나기");   // 맨 앞에 추가
    todoList.push_back("운동하기");     // 맨 뒤에 추가

    // 전체 요소 출력 (순차 순회)
    cout << "할 일 목록:" << endl;
    for (const string& todo : todoList) {
        cout << "- " << todo << endl;
    }

    // 요소 삭제
    todoList.pop_front();  // 맨 앞 요소 제거
    cout << "\n첫 번째 일 완료 후:" << endl;
    for (const string& todo : todoList) {
        cout << "- " << todo << endl;
    }

    cout << "\n=== map 기초 ===" << endl;

    map<string, int> scores;  // string을 key, int를 value로 갖는 map

    // 요소 추가
    scores["김철수"] = 90;                      // 대괄호 연산자 이용
    scores["이영희"] = 95;
    scores["박민수"] = 88;
    scores.insert(make_pair("최정화", 92));     // insert 함수 이용

    // 전체 출력 (키 기준 자동 정렬)
    cout << "학생 점수:" << endl;
    for (const auto& pair : scores) {
        cout << pair.first << ": " << pair.second << "점" << endl;
    }

    // 특정 키 검색
    string name = "이영희";
    if (scores.find(name) != scores.end()) {
        // 존재하면 출력
        cout << "\n" << name << "의 점수: " << scores[name] << "점" << endl;
    }

    // 키 존재 여부 확인
    cout << "박민수 등록됨? " << (scores.count("박민수") ? "예" : "아니오") << endl;
    cout << "홍길동 등록됨? " << (scores.count("홍길동") ? "예" : "아니오") << endl;

    return 0;
}
