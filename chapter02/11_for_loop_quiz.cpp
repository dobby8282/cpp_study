/*

초보
*
**
***
****
*****
******
*******

중급

   *
  ***
 *****
*******
 *****
  ***
   *
            i       j
   *        0       j > 3 + i
  ***       1       j > 3 + i
 *****      2       j > 3 + i
*******     3       j > 3 + i
 *****      4       j > 9 - i
  ***       5       j > 9 - i
   *        6       j > 9 - i
   
*/

#include <iostream>

using namespace std;

int main() {

    for(int i = 0; i < 7; i++) {

        for(int j = 0; j < 7; j++) {

            if(i < 4) {
                if(j < 3 - i) {
                    cout << " ";
                } else if(j > 3 + i) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            } else {
                if(j < i - 3) {
                    cout << " ";
                } else if(j > 9 - i) {
                    cout << " ";
                } else {
                    cout << "*";
                }
            }
        }
        cout << endl;
    }


    return 0;
}

