/*
파일명: 06_constructor_overloading.cpp

생성자 오버로딩
    서로 다른 매개변수를 가진 여러 개의 생성자를 정의
*/
#include <iostream>
using namespace std;

class Circle {

private : 
    double radius;

public :
    Circle() : radius(1.0) {
        cout << "기본 생성자" << endl;
    }

    Circle(double r) : radius(r) {
        cout << "Circle(double r) 생성자" << endl;
    }
    Circle(int r) : radius(r) {
        cout << "Circle(int r) 생성자" << endl;
    }

    double getArea() {
        return 3.141592 * radius * radius;
    }

    void display() {
        cout << "반지름: " << radius << ", 넓이: " << getArea() << endl;
    }
};

int main() {
    Circle c1;
    Circle c2(5.0);
    Circle c3(10);

    c1.display();
    c2.display();
    c3.display();


    return 0;
}