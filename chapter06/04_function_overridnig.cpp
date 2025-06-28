/* 
파일명: 04_function_overridnig.cpp

함수 오버라이딩 (Function Overriding)
    자식 클래스에서 부모 클래스의 함수를 재정의 하여
    다른 동작을 구현하는 기법

오버라이딩 vs 오버로딩
    - 오버라이딩 : 상속 관계에서 같은이름의 함수 재정의
    - 오버로딩 : 같은 클래스 내에서 같은 이름, 다른 매개변수 함수들
*/

#include <iostream>
using namespace std;

class Shape {

protected : 
    string name;

public :
    Shape(string n) : name(n) {}

    void display() {
        cout << "도형: " << name << endl;
    }

    double getArea() {
        cout << "기본 도형의 넓이" << endl;
        return 0;
    }

};

class Circle : public Shape {
private : 
    double radius;
public : 
    Circle(double r) : Shape("원"), radius(r) {}

    // 부모 클래스의 함수 오버라이딩
    double getArea() {
        cout << "원의 넓이 계산" << endl;
        return 3.14159 * radius * radius;
    }

    // 부모 함수 호출하기
    void showInfo() {
        Shape::display();   // 부모 클래스의 display호출
        cout << "반지름: " << radius << ", 넓이: "
         << getArea() << endl;
        
    }
};

int main() {
    Circle circle(5.0);

    circle.showInfo();

    return 0;
}