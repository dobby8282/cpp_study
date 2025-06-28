/* 파일명: 19_type_casting.cpp

형변환(Type Casting)
    하나의 데이터 타입을 다른 데이터 타입으로 변환하는 과정

암시적 변환: 컴파일러가 자동으로 수행하는 타입 변환
명시적 변환: 프로그래머가 의도적으로 지시하는 타입 변환

C++ 캐스트 연산자
    1. static_cast: 가장 일반적이고 안전한 캐스트(컴파일 타임)
    2. const_cast: const 속성 제거/추가
    3. reinterpret_cast: 비트 패턴 재해석 (위험!)

*/

#include <iostream>

using namespace std;

int main() {

    cout << "=== 암시적 형변환 ===" << endl;
    int intValue = 10;
    double doubleValue = intValue;  // int -> double (자동)
    char charValue = 'A';
    int asciiValue = charValue;     // char -> int (자동)
    
    cout << "=== 명시적 형변환 ===" << endl;

    // C 스타일 캐스트
    double pi = 3.14159;
    int truncated = (int)pi;
    cout << "C 스타일: double " << pi << " -> int " << truncated << endl;

    // 1. static_cast (권장)
    double result = static_cast<double>(intValue) / 3;
    cout << "static_cast: " << intValue << " /3 = " << result << endl;

    // void* 포인터 활용
    void* voidPtr = &intValue; // 어떤 타입이든 저장 가능
    cout << "void* 주소: " << voidPtr << endl;

    // void*는 역참조 불가 -> 적절한 타입으로 캐스팅 필요
    int* intPtr = static_cast<int*>(voidPtr);
    cout << "캐스팅 후 값: " << *intPtr << endl;

    // 2. const_cast 
    int normalValue = 100;  // 원본은 non-const
    const int* constPtr = &normalValue; // const 포인터로 가리킴

    const int intVal = 200;
    
    cout << "원본 값: " << normalValue << endl;
    cout << "const 포인터로 읽기: " << *constPtr << endl;

    // const_cast로 const 제거
    int* modifialbePtr = const_cast<int*>(constPtr);
    *modifialbePtr = 200;

    cout << "원본 값: " << normalValue << endl;
    cout << "const_cast 후 " << *modifialbePtr << endl;

    // 3. reinterpret_cast - 비트 패턴 재해석
    int intForReinterpret = 0x41424344; // ASCII 'ABCD'
    char* charPtr = reinterpret_cast<char*>(&intForReinterpret);    // Little Endian "DCBA"
    cout << " int의 비트를 char*로 재해석: ";
    for(int i = 0; i < 4; i++) {
        cout << charPtr[i] << " ";
    }
    cout << endl;










    


    return 0;
}