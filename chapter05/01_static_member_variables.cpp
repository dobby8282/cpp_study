/*
파일명: 01_static_member_variables.cpp

정적(static) 멤버 변수
    모든 객체가 공유하는 클래스 레벨의 변수

*/

#include <iostream>
using namespace std;

class Student {

private :
    string name;
    static int totalCount;  // 정적 멤버 변수

public :
    Student(string n) : name(n) {
        totalCount++;
        cout << name << " 등록(총 " << totalCount << "명)" << endl;
    }

    ~Student() {
        totalCount--;
        cout << name << " 졸업" << endl;
    }

    static int getTotalCount() {
        return totalCount;
    }
};

// 정적 멤버 변수 초기화
int Student::totalCount = 0;

int main() {

    cout << "시작: " << Student::getTotalCount() << "명" << endl;

    {
        Student s1("김철수");
        Student s2("이영희");

        cout << "현재: " << Student::getTotalCount() << "명" << endl;

    }

    cout << "종료: " << Student::getTotalCount() << "명" << endl;

    return 0;
}