/* 파일명: 06_multiple_output.cpp

iomanip 사용하여 여러데이터 연속 출력하는 체이닝 기법 예제

 서식 설정
 setprecision: 전체 유효숫자개수 설정
 fixed: 고정 소수점 모드

 서식설정 해제
 resetiosflags
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double pi = 3.14159265359;
    int number = 42;
    string language = "C++";

    // 체이닝을 통한 연속 출력
    cout << "언어: " << language
        << ", 숫자: " << number
        << ", 원주율: " << pi << endl;  // 3.14159

    
    // 서식 지정
    cout << fixed << setprecision(2);
    cout << "원주율(소수점 2자리): " << pi << endl;

    // setprecision 기본값은 6자리
    cout << resetiosflags(ios::fixed) << setprecision(10);
    cout << pi << endl;




    return 0;
}
