/*파일명: 01_data_types.cpp

기본 데이터 타입

1. 정수형
    short       2바이트     -32,768~32,767
    int         4바이트     -2,147,483,648~2,147,483,647
    long        4/8바이트   4바이트면 int랑 같음 8바이트면 큰정수
    long long   8바이트     큰정수            

2. 실수형
    float       4바이트     7자리
    double      8바이트     15자리
    long double 8/16바이트

3. 문자형
    char        1바이트     -128~127    문자,작은정수

4. 논리형
    bool        1바이트     true/false

*/

#include <iostream>

using namespace std;

int main() {
    // 기본 데이터 타입들
    char ch = 'A';
    int num = 42;
    float f = 3.14f;
    double d = 3.14159;
    bool flag = true;

    cout << "=== 데이터 타입 크기 ===" << endl;
    cout << "char: " << sizeof(char) << "바이트, 값: " << ch << endl;
    cout << "int: " << sizeof(int) << "바이트, 값: " << num << endl;
    cout << "float: " << sizeof(float) << "바이트, 값: " << f << endl;
    cout << "double: " << sizeof(double) << "바이트, 값: " << d << endl;
    cout << "bool: " << sizeof(bool) << "바이트, 값: " << flag << endl;

    return 0;
}