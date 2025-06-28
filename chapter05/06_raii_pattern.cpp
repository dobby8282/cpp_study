/*
파일명: 06_raii_pattern.cpp

RAII 패턴 (Resource Acquisition Is Initialization)
    자원의 획득과 해제를 객체 생성과 소멸에 연결하여 자동 자원 관리를 수행하는 패턴            
*/

#include <iostream>
#include <fstream>

using namespace std;

class FileManager {
private :
    ofstream file;
    string filename;

public : 
    FileManager(const string& fname) : filename(fname) {

        string currentPath =  "/cpp_course/src/chapter05";
        string fullPath = currentPath + "/" + filename;

        cout << "fullPath: "<< fullPath << endl;

        file.open(fullPath);
        cout << "파일 열기: " << filename << endl;
    }

    ~FileManager() {
        if (file.is_open()) {
            file.close();
            cout << "파일 닫기: " << filename << endl;
        }
    }

    void write(const string& content) {
        if (file.is_open()) {
            file << content << endl;
        }
    }

};

class MemoryManager {
private : 
    int* data;

public :
    MemoryManager(int size) {
        data = new int[size];
        cout << "메모리 할당: " << data << endl;
    }

    ~MemoryManager() {
        delete[] data;
        cout << "메모리 해제: " << data << endl;
    }

    int* get() { return data; }

};

int main() {
    {
        FileManager fm("test.txt");
        fm.write("RAII 패턴 테스트");

        MemoryManager mm(10);
        mm.get()[0] = 42;
    }   // 여기서 자동으로 자원 해제

    cout << "자원이 안전하게 해제되었습니다." << endl;

    return 0;
}