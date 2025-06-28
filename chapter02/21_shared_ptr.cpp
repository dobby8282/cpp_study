/* 
파일명: 21_shared_ptr.cpp

공유 스마트 포인터 (Shared Smart Pointer)
    여러 포인터ㅕ가 하나의 객체를 공유할 수 있게 해주는 참조 카운팅 기반의 스마트 포인터

shared_ptr: 여러 포인터가 같은 객체를 공유할 수 있는 스마트 포인터
make_shared: shared_ptr을 효율적으로 생성해주는 헬퍼 함수
use_count(): 현재 객체를 참조하는 shared_ptr의 개수를 반환하는 함수

*/

#include <iostream>
#include <memory>
using namespace std;

int main() {
    auto ptr1 = make_shared<int>(100);
    cout << "값: " << *ptr1 << endl;
    cout << "참조 카운트: " << ptr1.use_count() << endl;
    {
        auto ptr2 = ptr1;   // 공유
        cout << "ptr2 생성 후 참조 카운트: " << ptr1.use_count() << endl;
    }   // ptr2 소멸

    cout << "ptr2 소멸 후 참조 카운트: " << ptr1.use_count() << endl;

    return 0;
}








