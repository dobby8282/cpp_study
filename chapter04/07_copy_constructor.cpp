/*
파일명: 07_copy_constructor.cpp

복사 생성자
    같은 클래스의 객체로 부터 새로운 객체를 복사 생성
*/
#include <iostream>
using namespace std;

class Array {

private : 
    int* data;
    int size;

public : 
    Array(int s) : size(s) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = i + 1;
        }
        cout << "Array(int s) 생성자 호출" << endl;
    }

    // 복사 생성자(깊은 복사)
    Array(const Array& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        cout << "복사 생성자 호출" << endl;
    }

    ~Array() {
        delete[] data;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array arr1(3);
    Array arr2 = arr1; // 복사 생성자 호출

    arr1.display();
    arr2.display();

    return 0;
}
