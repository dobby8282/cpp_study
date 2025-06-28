/* 
파일명: 02_class_basic.cpp

클래스 (class)
    데이터(멤버 변수)와 그 데이터를 조작하는 함수(멤버 함수)를 하나로 묶은 객체지향의 기본 단위

    - 캡슐화: 데이터와 함수를 하나로 묶어 외부에서의 접근 제어하는 개념
*/

#include <iostream>
using namespace std;

class Rectangle {

public:
    double width;
    double height;

    double getArea() {
        return width * height;
    }

    double getPerimeter() {
        return 2 * (width + height);
    }

    void display() {
        cout << "가로: " << width << ", 세로: " << height << endl;
        cout << "넓이: " << getArea() << ", 둘레: " << getPerimeter() << endl;
    }

};

int main() {

    Rectangle rect;
    rect.width = 5.0;
    rect.height = 3.0;

    cout << "=== 사각형 정보 ===" << endl;
    rect.display();

    return 0;
}