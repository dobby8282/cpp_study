/*
파일명: 05_virtual_function.cpp

가상 함수 (Virtual Function)
    런타임에 실제 객체 타입에 따라 호출되는 
    함수가 결정되는 함수

    동적 바인딩: 런타임에 실제 객체 타입을 기반으로 함수 호출 결정

    override 키워드 : 가상 함수를 재정의 할 때 사용하는 명시적 키워드

가상함수 vs 일반함수
    - 가상함수: 런타임에 실제 객체 타입의 함수 호출(동적 바인딩)
    - 일반함수: 컴파일 타임에 포인터 타입의 함수 호출(정적 바인딩)

*/
#include <iostream>
using namespace std;

class Animal{
public:
    // 가상 함수
    virtual void makeSound() {
        cout << "동물이 소리를 냅니다." << endl;
    }

    // 일반 함수
    void move() {
        cout << "동물이 움직입니다." << endl;
    }
};

class Dog : public Animal {
public : 
    
    void makeSound() override {  // makeSound 함수 오버라이딩
        cout << "멍멍!" << endl;
    }

    void move() {
        cout << "개가 뛰어다닙니다." << endl;
    }
};

class Cat : public Animal {

public : 
    void makeSound() override {
        cout << "야옹!" << endl;
    }

    void move() {
        cout << "고양이가 조용히 걷습니다." << endl;
    }
};

int main() {

    Dog dog;
    Cat cat;

    cout << "=== 직접 호출 ==="  << endl;
    dog.makeSound();
    cat.makeSound();

    cout << "=== 포인터 호출 ==="  << endl;

    Animal animal0;
    Animal* animal1 = &dog;
    Animal* animal2 = &cat;

    animal0.makeSound();
    animal1->makeSound();
    animal2->makeSound();

    animal0.move();
    animal1->move();
    animal2->move();

    return 0;
}

