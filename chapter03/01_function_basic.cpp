/* 
파일명: 01_function_basic.cpp

함수 (Function)
    특정 작업을 수행하는 코드 블록으로, 재사용 가능하고 모듈화된 프로그램 구성 요소

    - 함수 선언: 함수의 이름, 매개변수, 반환 타입을 컴파일러에게 알리는 것
    - 함수 정의: 함수가 실제로 수행할 작업을 구현하는 것
    - 함수 호출: 정의된 함수를 실행하는 것
    - 반환값: 함수가 처리 결과를 돌려주는 값
*/

#include <iostream>
#include <memory>
using namespace std;

// 함수 선언
int add(int a, int b);
void greet();

unique_ptr<int> create_num();

shared_ptr<int> create_shared_num();

int main() {
    // 함수 호출
    greet();

    int result = add(5, 3);
    cout << "5 + 3 = " << result << endl;

    auto num = create_num();
    cout << *num << endl;

    auto num2 = create_shared_num();
    cout << *num2 << endl;
    cout << num2.use_count() << endl;

    auto num3 = num2;
    cout << num3.use_count() << endl;

    return 0;
}

// 함수 정의
int add(int a, int b) { // int a = 5; int b = 3;
    return a + b;
}

void greet() {
    cout << "안녕하세요! 함수를 배워봅시다." << endl;
}

unique_ptr<int> create_num() {
    auto num = make_unique<int>(10);
    return num; // 자동으로 C++ 소유권 이전
}

shared_ptr<int> create_shared_num() {
    auto num = make_shared<int>(20);
    return num;
}


