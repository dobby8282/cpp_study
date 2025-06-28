/*
파일명: 02_class_template.cpp

클래스 템플릿 (Class Template)
    다양한 타입을 다를 수 있는 제네릭 클래스
*/
#include <iostream>
using namespace std;

template<typename T>
class Box {

private:
    T item;

public:
    Box(T i) : item(i) {}

    void setItem(T i) {
        item = i;
    }

    T getItem() {
        return item;
    }

    void display() {
        cout << "Box contains: " << item << endl;
    }
};

int main() {

    // 다양한 타입의 Box 생성
    Box<int> intBox(42);
    Box<string> stringBox("Hello");
    Box<double> doubleBox(3.14);

    intBox.display();
    stringBox.display();
    doubleBox.display();

    return 0;
}