/*
 * 파일명: 02_custom_exception.cpp
 * 
 * 주제: 사용자 정의 예외 (Custom Exception)
 * 정의: 도메인에 특화된 오류 상황을 표현하기 위해 예외 클래스를 직접 정의하고 사용
 * 
 * 핵심 개념:
 * - std::exception을 상속하여 커스텀 예외를 정의
 * - what() 함수 오버라이드로 오류 메시지 제공 (반드시 noexcept 지정)
 * - 예외 계층 설계로 구체적 예외를 유연하게 처리
 * - noexcept: 함수가 예외를 던지지 않음을 명시하여 안정성과 최적화 향상
 */

#include <iostream>       // 표준 입출력
#include <exception>      // 표준 예외 클래스
#include <string>         // 문자열 클래스
using namespace std;

// [1] 최상위 사용자 정의 예외 클래스
class BankException : public exception {
private:
    string message;

public:
    // 생성자: 예외 메시지 저장
    BankException(const string& msg) : message(msg) {}

    // what(): 예외 메시지 반환
    // noexcept 명시 → 예외 정보를 출력하는 함수는 예외를 던지지 않음이 보장되어야 함
    const char* what() const noexcept override {
        return message.c_str();
    }
};

// [2] 잔액 부족 예외 (구체적 예외)
class InsufficientFundsException : public BankException {
public:
    InsufficientFundsException(double requested, double available)
        : BankException("잔액 부족: 요청금액 " + to_string(requested) +
                        "원, 잔액 " + to_string(available) + "원") {}
};

// [3] 유효하지 않은 금액 예외 (구체적 예외)
class InvalidAmountException : public BankException {
public:
    InvalidAmountException()
        : BankException("유효하지 않은 금액입니다.") {}
};

// [4] 은행 계좌 클래스
class BankAccount {
private:
    double balance;  // 현재 잔액

public:
    BankAccount(double initial) : balance(initial) {}

    // 입금: 음수 또는 0원은 예외 발생
    void deposit(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        balance += amount;
        cout << amount << "원 입금 완료. 잔액: " << balance << "원" << endl;
    }

    // 출금: 음수, 또는 잔액 초과 시 예외 발생
    void withdraw(double amount) {
        if (amount <= 0) {
            throw InvalidAmountException();
        }
        if (amount > balance) {
            throw InsufficientFundsException(amount, balance);
        }
        balance -= amount;
        cout << amount << "원 출금 완료. 잔액: " << balance << "원" << endl;
    }

    // 잔액 조회 함수는 예외가 발생하지 않음 → noexcept 붙여도 좋음
    double getBalance() const noexcept { return balance; }
};

int main() {
    cout << "=== 사용자 정의 예외 ===" << endl;

    BankAccount account(100000);  // 초기 잔액 10만 원

    // [1] 다양한 예외 발생 상황 시뮬레이션
    try {
        account.deposit(50000);     // 정상 입금
        account.withdraw(30000);    // 정상 출금
        account.withdraw(-1000);    // 유효하지 않은 금액 (예외 발생)
    }
    catch (const InvalidAmountException& e) {
        cout << "금액 오류: " << e.what() << endl;
    }
    catch (const InsufficientFundsException& e) {
        cout << "잔액 오류: " << e.what() << endl;
    }
    catch (const BankException& e) {
        cout << "은행 오류: " << e.what() << endl;
    }

    // [2] 잔액 부족 예외 처리
    try {
        account.withdraw(200000);  // 잔액 초과 출금 (예외 발생)
    }
    catch (const BankException& e) {
        cout << "거래 실패: " << e.what() << endl;
    }

    // 최종 잔액 출력
    cout << "\n최종 잔액: " << account.getBalance() << "원" << endl;

    return 0;
}
