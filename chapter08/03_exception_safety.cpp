/*
 * 파일명: 03_exception_safety.cpp
 * 
 * 주제: 예외 안전성 (Exception Safety)
 * 정의: 예외가 발생해도 프로그램이 일관된 상태를 유지하도록 하는 프로그래밍 기법
 * 
 * 핵심 개념:
 * - 예외 안전성: 예외가 발생해도 자원이 누수되지 않고 객체가 유효한 상태를 유지하는 것
 * - RAII: 생성자에서 자원을 획득하고, 소멸자에서 해제 → 예외 발생 시에도 자동 정리
 * - 스마트 포인터: RAII를 이용한 자동 메모리 관리 도구 (unique_ptr, shared_ptr 등)
 * - noexcept: 예외가 발생하지 않음을 명시해 안정성과 최적화를 보장
 * 
 * 예외 안전성 수준:
 * - 기본 보장 (Basic Guarantee): 예외 발생 시 자원 누수 없음, 객체는 유효한 상태
 * - 강한 보장 (Strong Guarantee): 연산이 완료되지 않으면 상태가 변경되지 않음
 * - 예외 없음 보장 (No-throw Guarantee): 절대 예외를 던지지 않음 (noexcept 사용)
 * 
 * 관련 개념:
 * - 스마트 포인터, STL 컨테이너, 락 가드(RAII 기반 동기화)
 * - 예외 중립성, noexcept, 예외 명세, 재시도 가능한 트랜잭션 처리
 * 
 * 설계 팁:
 * - 자원은 RAII로 자동화하고, 수동 new/delete은 지양
 * - 복잡한 연산은 중간 상태 백업을 통해 강한 보장 고려
 * - 자주 호출되는 함수에 noexcept를 붙여 최적화 유도
 */

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// 자원 객체 클래스: 생성/소멸 시 로그 출력
class Resource {
private:
    string name;

public:
    Resource(const string& n) : name(n) {
        cout << "자원 생성: " << name << endl;
    }

    ~Resource() {
        cout << "자원 해제: " << name << endl;
    }

    void process() {
        cout << "자원 처리: " << name << endl;
    }
};

// ❌ 예외 안전하지 않은 클래스 (직접 new/delete 사용, RAII 미사용)
class UnsafeManager {
private:
    Resource* resource1;
    Resource* resource2;

public:
    UnsafeManager() : resource1(nullptr), resource2(nullptr) {}

    void initialize() {
        resource1 = new Resource("자원1");
        // 아래에서 예외 발생 시 resource1이 해제되지 않음 → 메모리 누수
        resource2 = new Resource("자원2");

        // 예외 발생 시뮬레이션
        throw runtime_error("초기화 중 오류 발생!");
    }

    ~UnsafeManager() {
        delete resource1;
        delete resource2;
    }
};

// ✅ 예외 안전한 클래스 (RAII + 스마트 포인터 사용)
class SafeManager {
private:
    unique_ptr<Resource> resource1;
    unique_ptr<Resource> resource2;

public:
    void initialize() {
        resource1 = make_unique<Resource>("안전자원1");
        resource2 = make_unique<Resource>("안전자원2");

        // 예외가 발생해도 unique_ptr이 자원을 자동으로 해제해 줌
        throw runtime_error("초기화 중 오류 발생!");
    }

    void process() {
        if (resource1 && resource2) {
            resource1->process();
            resource2->process();
        }
    }
};

// ✅ 강한 예외 안전성 보장 (작업 실패 시 원래 상태로 복원)
void strongExceptionSafety() {
    vector<int> data = {1, 2, 3, 4, 5};
    vector<int> backup = data;  // 원본 백업

    try {
        data.push_back(6);
        data.push_back(7);

        // 예외 발생 시뮬레이션
        if (data.size() > 6) {
            throw runtime_error("데이터 처리 오류!");
        }

        cout << "작업 성공!" << endl;
    }
    catch (...) {
        data = backup;  // 실패 시 원래 상태 복원
        cout << "오류 발생, 원래 상태로 복원됨" << endl;
        throw;  // 예외 재던지기
    }
}

int main() {
    cout << "=== 예외 안전하지 않은 코드 ===" << endl;
    try {
        UnsafeManager unsafe;
        unsafe.initialize();
    }
    catch (const exception& e) {
        cout << "오류: " << e.what() << endl;
    }

    cout << "\n=== 예외 안전한 코드 ===" << endl;
    try {
        SafeManager safe;
        safe.initialize();
    }
    catch (const exception& e) {
        cout << "오류: " << e.what() << endl;
        cout << "하지만 스마트 포인터 덕분에 자원은 안전하게 해제됨" << endl;
    }

    cout << "\n=== 강한 예외 안전성 ===" << endl;
    try {
        strongExceptionSafety();
    }
    catch (const exception& e) {
        cout << "최종 오류: " << e.what() << endl;
    }

    return 0;
}
