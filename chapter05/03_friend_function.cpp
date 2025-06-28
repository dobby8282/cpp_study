/* 
파일명: 03_friend_function.cpp

프렌드(friend) 함수
    클래스의 private 멤버에 접근할 수 있는 외부 함수
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {

private :
    double x, y;

public :
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    // firend 함수 선언
    friend double distance(const Point& p1, const Point& p2);
    friend ostream& operator<<(ostream& os, const Point& p);
};

// friend 함수 구현 - private 멤버에 직접 접근
double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

int main() {
    Point p1(3, 4);
    Point p2(0, 0);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "거리: " << distance(p1, p2) << endl;

    return 0;
}


