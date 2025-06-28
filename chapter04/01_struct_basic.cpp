/* 
파일명: 01_struct_basic.cpp

구조체 
    서로 다른 타입의 데이터를 하나의 단위로 묶어서 관리하는 사용자 정의 데이터 타입
*/
#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    // 구조체 변수 선언과 초기화
    Student student1;
    student1.name = "김철수";
    student1.age = 20;
    student1.gpa = 3.8;

    // 초기화 리스트 사용
    Student student2 = {"이영희", 19, 4.0};

    cout << "=== 학생 정보 ===" << endl;
    cout << "학생1: " << student1.name << ", " << student1.age << "세, GPA: " << student1.gpa << endl;
    cout << "학생2: " << student2.name << ", " << student2.age << "세, GPA: " << student2.gpa << endl;
}
