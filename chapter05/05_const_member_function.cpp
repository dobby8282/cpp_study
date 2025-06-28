/*
파일명: 05_const_member_function.cpp

const 멤버 함수 (Const Memeber Function)
    객체의 상태(멤버 변수)를 변경하지 않는다고 약속하는 멤버 함수   
    멤버 변수의 값을 읽을 수만 있고 수정할 수 없음
    
    mutable : const 함수에서도 수정 가능한 멤버 변수 지정
    const 객체 호출: const 객체는 const 멤버 함수만 호출 가능
*/

#include <iostream>
using namespace std;

class Book {
private :
    string title;
    int pages;
    mutable int readCount;

public : 
    Book(string t, int p) : title(t), pages(p), readCount(0) {}

    // const 멤버 함수
    string getTitle() const {
        readCount++;
        return title;
    }

    int getReadCount() const {
        return readCount;
    }

    int getPages() const {
        return pages;
    }

    // 비 const 멤버 함수
    void setPages(int p) {
        pages = p;
    }
};

int main() {
    Book book("C++", 500);
    const Book constBook("상수책", 300);

    book.setPages(520);
    cout << book.getTitle() << endl;
    cout << book.getPages() << endl;
    cout << book.getReadCount() << endl;
    cout << constBook.getTitle() << endl;
    cout << constBook.getPages() << endl;
    cout << constBook.getReadCount() << endl;
    // constBook.setPages(320);  // 오류: const 객체는 비 const 함수 호출 불가

    return 0;
}