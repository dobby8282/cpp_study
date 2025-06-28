/* 
파일명: 09_array_loops.cpp

배열과 반복문

*/

#include <iostream>
using namespace std;

int main() {

    int numbers[] = {2, 4, 6, 8, 10};
    int size = 5;

    // 일반 for 루프로 출력
    cout << "일반 for 루프: " << endl;
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;

    // 범위 기반 for 루프로 출력
    cout << "범위 기반 for 루프: " << endl;
    for (int num : numbers) {   
        cout << num << " ";
    }
    cout << endl;

    return 0;
}