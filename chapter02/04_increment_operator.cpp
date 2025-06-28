/* 파일명: 04_increment_operator.cpp

증감 연산자
    변수의 값을 1씩 증가시키거나 감소시키는 단항 연산자

    ++ (증가 연산자) : 변수의 값을 1 증가
    -- (감소 연산자) : 변수의 값을 1 감소

*/

#include <iostream>

using namespace std;

int main() {

    int x = 5;

    cout << "초기 x = " << x << endl;
    cout << "++x = " << (++x) << ", x = " << x << endl;

    x = 5;  // 초기화
    cout << "x++ = " << (x++) << ", x = " << x << endl;

    cout << "--x = " << (--x) << ", x = " << x << endl;

    return 0;
}