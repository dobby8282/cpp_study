/*
주제: 접근 지정자 (Access Specifiers in Inheritance)
정의: 상속 시 멤버들의 접근 권한을 제어하는 키워드

접근 제어자(Access Specifiers)
    클래스 멤버에 대한 외부 접근을 제어하는 키워드

    - public: 클래스 외부에서 자유롭게 접근 가능한 멤버
    - private: 클래스 내부에서만 접근 가능한 멤버
    - protected: 클래스 내부와 상속받은 클래스에서만 접근 가능한 멤버

    - 정보 은닉: 객체의 내부 구현을 외부에서 직접 접근하지 못하도록 숨기는 원칙

*/

#include <iostream>
using namespace std;

class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
    
public:
    Base() : publicVar(1), protectedVar(2), privateVar(3) {}
    
    void showBase() {
        cout << "Base - public: " << publicVar 
             << ", protected: " << protectedVar 
             << ", private: " << privateVar << endl;
    }
};

class Derived : public Base {
public:
    void showDerived() {
        cout << "Derived - public: " << publicVar << endl;      // OK
        cout << "Derived - protected: " << protectedVar << endl; // OK
        // cout << "Derived - private: " << privateVar << endl;  // 오류!
    }
    
    void setProtected(int value) {
        protectedVar = value;  // protected는 자식에서 접근 가능
    }
};

int main() {
    Derived d;
    d.publicVar = 10;        // OK: public 멤버
    // d.protectedVar = 20;  // 오류: protected는 외부에서 접근 불가
    
    d.showBase();
    d.showDerived();
    d.setProtected(99);
    d.showDerived();
    
    return 0;
}