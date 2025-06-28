/*
파일명: 09_operator_overloading.cpp

연산자 오버로딩
    사용자 정의 클래스에 대해 연산자의 동작을 정의
*/

#include <iostream>
using namespace std;

class Point {

private : 
    int x, y;

public : 
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // +연산자 오버로딩
    Point operator+(const Point& other) const { // const {} 내 객체 안건드린다!
        return Point(x + other.x, y + other.y);
    }

    // == 연산자 오버로딩
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    void display() {
        cout << " x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Point p1(3, 4);
    Point p2(1, 2);

    Point p3 = p1 + p2;

    p1.display();
    p2.display();
    p3.display();

    cout << "p1 == p2? " << (p1 == p2) << endl;

    return 0;
}