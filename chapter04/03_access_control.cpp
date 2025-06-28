/*
파일명: 03_access_control.cpp

접근 제어자(Access Specifiers)
    클래스 멤버에 대한 외부 접근을 제어하는 키워드

    - public: 클래스 외부에서 자유롭게 접근 가능한 멤버
    - private: 클래스 내부에서만 접근 가능한 멤버
    - protected: 클래스 내부와 상속받은 클래스에서만 접근 가능한 멤버

    - 정보 은닉: 객체의 내부 구현을 외부에서 직접 접근하지 못하도록 숨기는 원칙

*/


#include <iostream>
using namespace std;

class BankAccount {

private: 
    string accountNumber;
    double balance;

public: 
    void setAccount(string accNum, double initalBalance) {
        accountNumber = accNum;
        balance = initalBalance;
    }

    void deposit(double amount) {
        if(amount > 0) {
            balance += amount;
            cout << amount << "원 입금되었습니다." << endl;
        }
    }

    void withdraw(double amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << "원 출금되었습니다." << endl;
        } else {
            cout << "출금할 수 없습니다." << endl;
        }
    }

    void displayBalance() {
        cout << "계좌번호: " << accountNumber << ", 잔액: " << balance << "원" << endl;
    }

};

int main() {
    BankAccount account;
    account.setAccount("123-456-789", 100000);

    account.displayBalance();

    account.deposit(50000);
    account.displayBalance();

    account.withdraw(30000);
    account.displayBalance();


    // account.balance = 1000000;  // 오류: private 멤버에 직접 접근 불가

    return 0;

}