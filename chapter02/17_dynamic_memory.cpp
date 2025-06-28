/* 
파일명: 17_dynamic_memory.cpp

동적 메모리 할당(Dynamic Memory Allocation)
    프로그램 실행 중에 필요에 따라 힙(heap) 메모리 영역에서 메모리를 할당하고 해제하는 기법

C++ 메모리 구조 (Memory Layout):
┌─────────────────┐ ← 높은 주소 (0xFFFFFFFF)
│   커널 영역      │   (운영체제 전용)
├─────────────────┤
│   스택 (Stack)   │   - 지역변수, 함수 매개변수, 리턴 주소 저장
│       ↓        │   - 함수 호출 시 자동 생성, 함수 종료 시 자동 해제
│                │   - 크기 제한 있음 (보통 1-8MB)
│                │   - 빠른 접근 속도
├─────────────────┤
│   힙 (Heap)     │   - new/malloc으로 동적 할당되는 영역
│       ↑        │   - 프로그래머가 직접 관리 (new/delete)
│                │   - 크기 제한 거의 없음 (시스템 메모리까지)
│                │   - 상대적으로 느린 접근 속도
├─────────────────┤
│ 데이터 영역(BSS) │   - 초기화되지 않은 전역/정적 변수
├─────────────────┤
│ 데이터 영역(Data)│   - 초기화된 전역/정적 변수
├─────────────────┤
│ 코드 영역(Text)  │   - 실행 가능한 코드(기계어)
└─────────────────┘ ← 낮은 주소 (0x00000000)


    - new: 힙 메모리에 새로운 객체를 할당하는 연산자
    - delete: new로 할당된 메모리를 해제하는 연산자
    - 스택 vs 힙: 스택은 자동 관리, 힙은 수동 관리가 필요한 메모리 영역
    - nullptr: null 포인터 리터럴, 포인터가 아무것도 가리키지 않는다는 것을 명시적으로 나타냄

*/

#include <iostream>

using namespace std;

// 데이터 영역(Data Segment) - 초기화된 전역변수
int globalInitialized = 300;

// BSS 영역(BSS Segment) - 초기화되지 않은 전역변수 (자동으로 0으로 초기화)
int globalUnInitialized;

// 정적 변수도 데이터 영역에 저장됨
static int staticGlobal = 400;

void showStaticVariable() {

    // 정적 지역변수 - 데이터 영역에 저장되지만 지역 범위를 가짐
    static int staticLocal = 500;

    cout << "\n=== 정적 변수 (데이터 영역에 저장) ===" << endl;
    cout << "정적 지역변수: " << staticLocal << ", 주소: " << &staticLocal << endl;

    staticLocal++;  // 함수 호출 시 마다 값이 유지됨

}



int main() {

    cout << "=== C++ 메모리 구조 이해 ===" << endl;

    // 스택 메모리 (자동관리)
    int stackVar = 100;     // 지역변수
    cout << "스택 변수: " << stackVar << ", 주소: " << &stackVar << endl;

    // 힙 메모리 (수동관리)
    int* heapPtr = new int(200);

    cout << "힙 변수: " << *heapPtr << ", 주소: " << heapPtr << endl;
    cout << "포인터 자체 주소(스택): " << &heapPtr << endl;
    

    // 정적 변수 확인
    showStaticVariable();
    showStaticVariable();   // 두 번 호출해서 값이 유지되는지 확인

    // 메모리 주소 비교
    cout << "\n=== 메모리 주소 비교 ===" << endl;
    cout << "전역변수 주소: " << &globalInitialized << "(데이터 영역)" << endl;
    cout << "스택변수 주소: " << &stackVar << "(스택 영역)" << endl;
    cout << "힙변수 주소: " << heapPtr << "(힙 영역)" << endl;

    delete heapPtr;

    cout << "해제 후 힙 변수: " << *heapPtr << ", 주소: " << heapPtr << endl;

    heapPtr = nullptr;  // 댕글링 포인터 방지
    // heapPtr = NULL; // C 스타일(권장하지 않음)

    return 0;
}







