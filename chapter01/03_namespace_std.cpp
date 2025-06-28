/* 파일명: 03_namespace_std.cpp

using 
    using 지시문을 통해 네임스페이스 사용을 간소화 할수 있습니다.
*/

#include <iostream>

using namespace std;

int main() {
    cout << "using name space std 사용" << endl;
    cout << "std:: 접두사 생략 가능" << endl;

    return 0;   
    
}
