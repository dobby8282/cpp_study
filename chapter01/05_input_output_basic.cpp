/* 파일명: 05_input_output_basic.cpp

cin/cout 
    C++의 스트림 기반 입출력 명령어
    C의 scanf/printf와 달리 C++의 cin/cout은 타입 안정성을 제공하며 더 직관적이다

스트림연산자(<<, >>)
    << : 출력스트림
    >> : 입력스트림
*/

#include <iostream>

using namespace std;

int main() {

    string name; // 문자열 담을수 있는 변수
    int age;    // 정수 값을 담을수 있는 변수

    cout << "이름을 입력하세요: ";
    cin >> name;

    cout << "나이를 입력하세요: ";
    cin >> age;

    cout << "안녕하세요, " << name << "님!" << endl;
    cout << "나이: " << age << "세" << endl;

    return 0;
}