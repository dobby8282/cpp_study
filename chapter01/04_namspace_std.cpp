/* 파일명: 04_namspace_std.cpp

선택적 using 선언
*/

#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "선택적 using 선언" << endl;
    // std::cin은 여전히  std:: 필요

    return 0;
}