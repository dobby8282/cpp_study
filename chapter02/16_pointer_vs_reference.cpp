/* 파일명: 16_pointer_vs_reference.cpp

포인터 vs 레퍼런스

    재할당 가능성: 포인터는 다른 변수를 가리킬 수 있지만 레퍼런스는 불가능
    초기화 요구사항: 레퍼런스는 선언 시 반드시 초기화, 포인터는 나중에 가능
    문법차이: 포인터는 *로 역참조 필요, 레퍼런스는 직접 사용
*/

#include <iostream>
using namespace std;

int main() {

    int a = 10, b = 20;

    // 레퍼런스
    int& ref = a;
    cout << "레퍼런스: " << ref << endl;

    // 포인터
    int* ptr = &a;
    cout << "포인터가 가리키는 값: " << *ptr << endl;

    // 포인터는 재할당 가능
    ptr = &b;
    cout << "포인터 재할당 후: " << *ptr << endl;

    // 레퍼런스는 재할당 불가능 (다른 변수 참조 불가)
    // ref = b;


    return 0;
}

