/* 파일명: 14_reference_basic.cpp

레퍼런스(Reference)
    기존 변수에 대한 별명(alias)으로, 같은 메모리 위치를 참조하는 또다른 이름

    레퍼런스(&) : 변수 선언 시 &를 붙여 다른 변수의 별명을 만드는 문법
    초기화 필수: 레퍼런스는 선언과 동시에 반드시 초기화되어야 하는 특성

*/

#include <iostream>

using namespace std;

int main() {

    int original = 100;
    int& ref = original;

    cout << "원본: " << original << endl;
    cout << "레퍼런스" << ref << endl;
    cout << "같은 주소? " << (&original == &ref) << endl;

    // 레퍼런스로 값 변경
    ref = 200;
    cout << "레퍼런스로 변경 후 원본: " << original << endl;


    return 0;
}