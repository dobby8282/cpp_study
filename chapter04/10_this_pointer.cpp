/* 
파일명: 10_this_pointer.cpp

this 포인터
    현재 객체를 가리키는 포인터
*/

#include <iostream>

using namespace std;

class Calculator {

private :
    int value;
public :
    Calculator(int v = 0) : value(v) {}

    Calculator& add(int n) {
        this -> value += n; // (*this).value += n;
        return *this;
    }

    Calculator& multiply(int n) {
        this -> value *= n;
        return *this;
    }

    bool isEqual(const Calculator& other) {
        return this -> value == other.value;
    }

    void display() {
        cout << "값: " << value << endl;
    }

};

int main() {
    Calculator calc(5);

    // 메서드 체이닝
    calc.add(3).multiply(2);
    calc.display(); 

    Calculator calc2(16);
    cout << "같은가? " << calc.isEqual(calc2) << endl;

    return 0;
}
