/*
파일명: 03_constructor_destructor_order.cpp

생성자/소멸자 호출 순서
    상속 관계에서 생성자는 부모->자식 소멸자는 자식->부모 순으로 호출
*/

#include <iostream>
using namespace std;

class Base {
private : 
    int privateData;
protected :
    int protectedData;
public :
    int publicData;

    Base() {
        cout << "Base 생성자" << endl;
    }

    ~Base() {
        cout << "Base 소멸자" << endl;
    }
};

class Derived : protected Base {
    /*
    publicData -> protcted로 변경
    protectedData -> protected 유지
    privateData -> 접근불가
    */
public :   

    Derived() {
        publicData = 10;
        protectedData = 20;
        // privateData = 30;
        cout << "Derived 생성자" << endl;
    }

    ~Derived() {
        cout << "Derived 소멸자" << endl;
    }
};

class GrandChild : private Derived {
    /*
    publicData -> private 변경
    protectedData -> private 변경
    privateData -> 접근불가
    
    */
public : 
    GrandChild() {
        publicData = 10;
        protectedData = 20;
        // privateData = 30;
        cout << "GrandChild 생성자" << endl;
    }

    ~GrandChild() {
        cout << "GrandChild 소멸자" << endl;
    }
};

int main() {
    cout << "=== 객체 생성 ===" << endl;
    {
        GrandChild gc;

        // gc.publicData = 10;
        // gc.protectedData = 20;
        // gc.privateData = 30;

    }
    cout << "=== 객체 소멸 ===" << endl;
}
