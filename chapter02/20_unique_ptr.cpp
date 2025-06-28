/* 
파일명: 20_unique_ptr.cpp

스마트 포인터 (Smart Pointers)
    자동으로 메모리를 관리해주는 포인터 래퍼 클래스로, 메모리 누수를 방지 (C++11)

unique_ptr: 하나의 객체를 동점적으로 소유하는 스마트 포인터
make_unique: unique_ptr을 안전하게 생성하는 헬퍼 함수
auto: 컴파일러가 변수의 타입을 자동으로 추론하게 하는 키워드(C++11)

unique_ptr 독점 특성:
    - 복사 불가능 unique_ptr은 복사 생성자와 복사 대입 연산자가 삭제됨
    - 이동 가능: std::move를 통해 소유권 이전 가능
    - 하나의 객체는 한번에 하나의 unique_ptr만 소유 가능
    - 소유권 이전 시 기존 unique_ptr은 nullptr이 됨

auto 키워드 특징:
    - 컴파일 타임에 타입 자동 추론
    - 복잡한 타입명을 간단하게 표현
    - 템플릿과 함께 사용 시 매우 유용
    - 초기화 표현식을 기반으로 타입 결정

*/

#include <iostream>
#include <memory>

using namespace std;

int main() {

    // 일반 포인터 (수동관리)
    int* rawPtr = new int(123);
    cout << "일반 포인터 값: " << *rawPtr << endl;
    delete rawPtr;  // 수동으로 해제 필요
    rawPtr = nullptr;

    auto ptr1 = make_unique<int>(42);   // 스코프를 벗어날 때 자동으로 메모리 해제하는 기능

    unique_ptr<int> ptr2 = make_unique<int>(100);

    // auto ptr3 = ptr1; // 에러! unique_ptr은 복사 불가능

    // 소유권 이전(이동)
    cout << "이동전: " << endl;
    cout << "ptr1 포인터: " << ptr1.get() << ", 값: " << *ptr1 << endl;

    auto moved = move(ptr1);
    cout << "이동후: " << endl;
    cout << "moved 포인터: " << moved.get() << ", 값: " << *moved << endl;
    cout << "ptr1 포인터: " << ptr1.get() << " (nullptr)" << endl;

    // unique_ptr (자동 관리)
    {
        auto smartPtr = make_unique<int>(456);

        cout << "스마트 포인터 값: " << *smartPtr << endl;
        // 스코프 종료시 자동으로 해제
                
    }
    cout << "스마트 포인터는 자동으로 해제됨" << endl;


    cout << "=== unique_ptr 유용한 멤버 함수들 ===" << endl;

    auto ptr4 = make_unique<int>(777);

    // get(): 내부 포인터 반환
    int* rawAddress = ptr4.get();
    cout << "get()으로 주소 얻기: " << rawAddress << ", 값: " << *rawAddress << endl;

    // reset(): 새로운 포인터로 재설정
    ptr4.reset(new int(888));
    cout << "reset() 후 값: " << *ptr4 << endl;

    // release(): 소유권 포기하고 포인터 반환
    int* releasePtr = ptr4.release();
    cout << "release() 후:" << endl;
    cout << "ptr4: " << ptr4.get() << " (nullptr)" << endl;
    cout << "releasePtr: " << releasePtr << ", 값: " << *releasePtr << endl;
    delete releasePtr;  // release() 후에는 수동 삭제 필요


    return 0;

}