/* 파일명: 12_while_loop.cpp

while 반복문
    주어진 조건이 참인 동안 반복실행 제어 구조

do-while 반복문
    코드 블록을 먼저 실행한 후 조건을 검사하여 반복을 결정하는 후검사 반복문
    조건 관계없이 최초 1회 실행

*/

#include <iostream>
using namespace std;

int main() {

    int num;
    int sum = 0;

    cout << "숫자를 입력하세요(0 입력시 종료): " << endl;

    while(true) {
        cout << "숫자: ";
        cin >> num;

        if (num == 0) {
            break;
        }

        sum += num;     // 복합대입연산자 sum = sum + num;
        cout << "현재 합계: " << sum << endl;
    }

    cout << "최종 합계: "  << sum << endl;


    // do-while 예제

    int choice;

    do {
        cout << "\n=== 메뉴 ===" << endl;
        cout << "1. 아메리카노" << endl;
        cout << "2. 라떼" << endl;
        cout << "3. 아이스초코" << endl;
        cout << "4. 종료" << endl;
        cout << "선택: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "아메리카노를 주문하셨습니다." << endl;
                break;
            case 2:
                cout << "라떼를 주문하셨습니다." << endl;
                break;
            case 3:
                cout << "아이스초코를 주문하셨습니다." << endl;
                break;
            case 4:
                cout << "주문을 종료합니다." << endl;
                break;
            default:
                cout << "잘못된 선택입니다." << endl;
        }

    } while(choice != 4);

    return 0;
}
