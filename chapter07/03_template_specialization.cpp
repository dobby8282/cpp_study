/*
파일명: 03_template_specialization.cpp

템플릿 특수화
    다양한 타입을 다룰수 있는 템플릿 에서
    특정 타입만 특별하게 구현하는 방법
*/

#include <iostream>
using namespace std;


// 기본 템플릿
template<typename T>
void show(T value) {
    cout << "값: " << value << endl;
}

template<>
void show<string>(string value) {
    cout << "문자열: \"" << value << "\"" << endl;
}
template<>
void show<const char*>(const char* value) {
    cout << "리터럴 문자열: \"" << value << "\"" << endl;
}

int main() {

    show(42);
    show(3.14);

    show("안녕");           // show<const char*>
    show(string("안녕"));   // show<string>

    return 0;
}


