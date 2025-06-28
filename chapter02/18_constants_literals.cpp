/*
파일명: 18_constants_literals.cpp

상수와 리터럴
    프로그램 실행 중 값이 변경되지 않는 데이터와 코드에 직접 기술된 고정값

프로그램 실행 단계:
1. 전처리(Preprocessing):
    - #include, #define 등 전처리 지시문 처리
    - 매크로 치환, 헤더 파일 포함
    - 소스 코드 -> 전처리 소스코드

2. 컴파일 타임(Compile Time):
    - 전처리된 소스 코드를 기계어로 번역
    - 문법 검사, 타입 검사, 최적화 수행
    - constexpr 값들이 이 단계에서 계산됨
    - 소스 코드 -> 오브젝트 파일(.obj, .o)

3. 링크 타임(Link Time):
    - 여러 오브젝트 파일을 하나의 실행 파일로 결함
    - 라이브러리 연결, 외부 참조 해결

4. 런타임(Runtime):
    - 실제 프로그램이 실행되는 시점
    - const 변수의 값이 결정되고 메모리에 저장
    - 사용자 입력, 계산 결과 등이 처리됨


시간 순서: 전처리 -> 컴파일 -> 링크 -> 런타임

상수 타입별 장단점
1. 매크로 
    장점: 전처리 단계에서 치환, 조건부 컴파일 가능
    단점: 타입 안전성 없음, 디버깅 어려움, 스코프 무시
2. constexpr
    장점: 컴파일 타임 계산, 타입 안전성, 성능 최적화
    단점: 컴파일 타임에 값이 결정되어야 함
3. const
    장점: 타입 안전성, 스코프 존중, 런타임 값 사용 가능
    단점: 런타임 메모리 사용


*/

#include <iostream>

using namespace std;

// 매크로 상수 정의
#define MAX_BUFFER_SIZE 1024
#define VERSION "2.1.0"
#define SQUARE(x) ((x) * (x))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {

    cout << "=== 프로그램 실행 단계별 상수 처리 ===" << endl;

    // 전처리 단계: 매크로 치환
    cout << "1. 전처리: #define MAX_BUFFER_SIZE -> " << MAX_BUFFER_SIZE << endl;
    cout << "   (소스 코드에서 MAX_BUFFER_SIZE가 1024로 치환됨)" << endl;

    // 컴파일 타임: constexpr 계산
    constexpr int ARRAY_SIZE = 10;
    constexpr double GRAVITY = 9.8;
    constexpr int CALCUATED = SQUARE(5);    // 컴파일 시점에 25로 계산

    cout <<"2. 컴파일 타임: constexpr 값들이 미리 계산됨" << endl;
    cout <<"   constexpr int ARRAY_SIZE = " << ARRAY_SIZE << endl;
    cout <<"   constexpr double GRAVITY = " << GRAVITY << endl;
    cout <<"   constexpr int CALCUATED = " << CALCUATED << " (5*5가 컴파일 시 계산됨)" << endl;

    // 런타임: const 상수 초기화
    const int MAX_STUDENTS = 30;
    const double PI = 3.14159;
    const string SCHOOL_NAME = "C++ 학원";

    cout << "3. 런타임: const 변수들이 실행 시점에 초기화됨" << endl;
    cout << "   const int MAX_STUDENTS = " << MAX_STUDENTS << endl;
    cout << "   const double PI = " << PI << endl;
    cout << "   const string SCHOOL_NAME = " << SCHOOL_NAME << endl;

    // MAX_STUDENTS = 10; // 상수는 값 변경 불가
    


    return 0;
}