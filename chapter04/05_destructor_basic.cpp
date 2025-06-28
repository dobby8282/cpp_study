/*
파일명: 05_destructor_basic.cpp

소멸자(Destructor)
    객체가 소멸될 때 자동으로 호출되어 정리 작업을 수행하는 함수

*/
#include <iostream>
using namespace std;

class Resource {
private : 
    int* data;

public :
    Resource(int size) {
        data = new int[size];
        cout << "메모리 할당: " << data << endl;
    }

    ~Resource() {   // 소멸자
        delete[] data;  // 동적메모리 배열 해제
        cout << "메모리 해제: " << data << endl;
    }

    void setValue(int value) {
        data[0] = value;
    }
};

int main() {
    
    Resource r(10);
    r.setValue(42);
    
    cout << "메인 계속 실행" << endl;
    return 0;
    
}
