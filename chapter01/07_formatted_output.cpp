/*파일명: 07_formatted_output.cpp 

setw : 출력 폭 설정
left : 왼쪽 정렬
right : 오른쪽 정렬

*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double price = 1234.567;
    string product = "노트북";
    int quantity = 5;

    cout << "=== 상품 정보 ===" << endl;
    cout << left << setw(10) << "상품명"
        << right << setw(10) << "단가"
        << right << setw(8) << "수량"
        << right << setw(12) << "총액" << endl;
    
    cout << string(40, '-') << endl;
    cout << left << setw(10) << product
        << right << setw(10) << fixed << setprecision(0) << price
        << right << setw(8) << quantity
        << right << setw(12) << price * quantity << endl;

    // 퍼센트 출력
    double rate = 0.15;
    cout << "\n할인율: " << setprecision(1) << (rate * 100) << "%" << endl;


    return 0;
}

/*

=== 상품 정보 ===
상품명     단가  수량      총액        
----------------------------------------
노트북       1235       5        6173  

할인율: 15.0%
*/