/*
파일명: 04_constructor_basic.cpp

생성자(Constructor)
    객체가 생성될 때 자동으로 호출되어 객체를 초기화하는 특별한 멤버 함수
    클래스 이름과 동일하며 반환값이 없음
    객체 생성 시 자동 호출되어 멤버변수 초기화
*/

#include <iostream>
using namespace std;

class Student {

public:
    
    string name;
    int age;

    // 기본 생성자
    Student() : name("Unknown"), age(0) {
        cout << "기본 생성자: " << name << endl;
    }

    void display() {
        cout << name << " (" << age << "세)" << endl;
    }
};

int main() {
    Student s1;
    s1.name = "홍길동";
    s1.age = 25;

    Student s2;
    
    s1.display();
    s2.display();

    return 0;
}




