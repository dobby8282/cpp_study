/*
파일명: 06_virtual_destructor.cpp

가상 소멸자 (Virtual Destructor)
    상속 관계에서 올바른 소멸자 호출을 보장하는 가상 소멸자
*/

#include <iostream>
using namespace std;

class Base {
public :
    Base() {
        cout << "Base 생성자" << endl;
    }

    // 가상 소멸자 - 중요!
    virtual ~Base() {
        cout << "Base 소멸자" << endl;
    }

    virtual void display() {
        cout << "Base 클래스" << endl;
    }
};

class Derived : public Base {
private :
    int* data;

public :
    Derived() {
        data = new int[10];
        cout << "Derived 생성자 (메모리 할당)" << endl;
    }

    ~Derived() {
        delete[] data;
        cout << "Derived 소멸자 (메모리 해제)" << endl;
    }

    void display() override {
        cout << "Derived 클래스" << endl;
    }

};

int main() {

    cout << "=== 직접 객체 생성 ===" << endl;
    {
        Derived d;
        d.display();
    }

    cout << "\n=== 포인터를 통한 동적 할당 ===" << endl;
    {
        Base* ptr = new Derived();  
        ptr->display();  
        delete ptr;      
    }

    return 0;

}
