/*
파일명: 07_abstract_class.cpp

추상 클래스 (Abstract Class)
    하나 이상의 순수 가상 함수를 가진 클래스로, 인터페이스 역할
    미완성 클래스

    인터페이스 : 클래스가 반드시 구현해야하는 함수들의 명세서

순수 가상 함수 (Pure Virtual Function)
    구현이 없는 가상 함수로, 자식 클래스에서 반드시 구현해야 함

다형성 (Polymorphism)
    하나의 인터페이스로 다양한 타입의 객체를 처리하는 능력

dynamic_cast
    런타임에 안전한 타입 변환을 수행하는 캐스팅 연산자
    상속 관계에서 다운캐스팅(부모->자식)과 크로스캐스팅 안전하게 수행
*/

#include <iostream>
#include <memory>
using namespace std;

// 기본 클래스
class Vehicle {
protected :
    string brand;
public :
    Vehicle(string b) : brand(b) {}
    virtual ~Vehicle() {}

    virtual void start() = 0;   // 순수 가상 함수
    virtual void stop() = 0;   // 순수 가상 함수
};

// 파생 클래스
class Car : public Vehicle {
public :
    Car(string b) : Vehicle(b) {}

    void start() override {
        cout << brand << " 자동차 시동! 부릉부릉!" << endl;
    }

    void stop() override {
        cout << brand << " 자동차 정지!" << endl;
    }

    void printCar() {
        cout << "자동차 입니다" << endl;
    }
};

class Motorcycle : public Vehicle {

public :
    Motorcycle(string b) : Vehicle(b) {}

    void start() override {
        cout << brand << " 오토바이 시동! 붕붕!" << endl;
    }

    void stop() override {
        cout << brand << " 오토바이 정지!" << endl;
    }

    void printBike() {
        cout << "오토바이 입니다" << endl;
    }

};


int main() {

    // 객체 생성
    Car car("현대");
    Motorcycle bike("혼다");
    // Vehicle train("코레일"); // 추상 클래스 객체생성 불가

    // car.start();
    // car.stop();
    // bike.start();
    // bike.stop();

    Vehicle* vehicles[] = {&car, &bike};
    for(int i = 0; i < 2; i++) {
        vehicles[i]->start();   // 각 객체의 실제 start() 호출
        vehicles[i]->stop();    // 각 객체의 실제 stop() 호출

        // vehicles[i]->printCar();
        if(Car* car = dynamic_cast<Car*>(vehicles[i])) {
            car->printCar();
        } else if(Motorcycle* bike = dynamic_cast<Motorcycle*>(vehicles[i])) {
            bike->printBike();
        }

    }
    
    return 0;
}