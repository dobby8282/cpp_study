/* 파일명: 15_pointer_basic.cpp

포인터(Pointer)
    다른 변수의 메모리 주소를 저장하는 변수로, 
    간접적으로 메모리에 접근할 수 있게 해주는 도구

    포인터(*): 메모리 주소를 저장하는 변수 타입
    주소 연산자(&): 변수의 메모리 주소를 얻는 연산자
    역참조(*): 포인터가 가리키는 메모리 위치의 값에 접근하는 연산자


*/

#include <iostream>

using namespace std;

int main() {

    int value = 42;
    int* ptr = &value;  // 포인터 생성

    cout << "변수 값: " << value << endl;
    cout << "변수 주소: " << &value << endl;
    cout << "포인터 값(주소): " << ptr << endl;
    cout << "포인터가 가리키는 값: " << *ptr << endl;

    // 포인터로 값 변셩
    *ptr = 100;
    cout << "포인터로 변경 후 " << value << endl;


    return 0;
}
