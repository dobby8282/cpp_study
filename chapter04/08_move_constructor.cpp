/*
파일명: 08_move_constructor.cpp

이동 생성자(Move Constructor)
    임시 객체로 부터 자원을 효율적으로 이동하는 생성자


reference 연산자
    lvalue : 이름있는 변수를 가리키는 별명
    rvalue : 임시로 생긴 값을 붙잡는 별명

    예)
        int& ref1 = x;      // &: 이름있는 변수 x 참조
        int&& ref2 = 10;    // &&: 임시값 10 붙잡기
        int&& ref3 = move(x) // x를 "곧 사라질 것"으로 취급
*/

#include <iostream>
#include <cstring>
using namespace std;

class StringHolder {

private :
    char* str;

public : 
    StringHolder(const char* s) {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        cout << "생성: " << str << endl;
    }

    // 이동 생성자
    StringHolder(StringHolder&& other) : str(other.str) {   // other s1 임시 저장
        other.str = nullptr;
        cout << "이동 생성" << endl;
    }

    ~StringHolder() {
        if (str) {
            cout << "소멸: " << str << endl;
            delete[] str;
        }
        cout << "소멸자 ~StringHolder()" << endl;
    }

    void display() {
        cout << (str ? str : "비어있음") << endl;
    }
};

int main() {
    StringHolder s1("Hello");
    StringHolder s2 = move(s1); // 이동 생성자
  
    s1.display();
    s2.display();

    return 0;
}