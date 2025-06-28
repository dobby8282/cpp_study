/* 파일명: 08_comments_usage.cpp

주석
    프로그램에 영향을 주지 않으면서 코드에 설명을 달아놓는것입니다.
*/

#include <iostream>

using namespace std;

/**
 * 원의 넓이를 계산하는 프로그램
 * 작성자: C++ 개발팀
 * 버전: 1.0
 */
int main() {
    const double PI = 3.14159;  // 원주율 상수
    double radius;              // 반지름

    cout << "원의 반지름을 입력하세요: ";
    cin >> radius;

    // 원의 넓이 계산
    double area = PI * radius * radius;

    cout << "원의 넓이: " << area << endl;

    
    return 0;
}

