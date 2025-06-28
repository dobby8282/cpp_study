/* 파일명: 02_namespace_basic.cpp 

네임스페이스 
    네임스페이스는 C++의 핵심 기능중 하나로, 
    대규모 프로젝트에서 이름 충돌방지하고 코드를 논리적으로 조직화 하는
    중요한 메카니즘입니다

    namespace 키워드
    범위해석연산자 scope resolution operator(::)
*/

#include <iostream>

namespace Graphics {
    void draw() {
        std::cout << "Graphics::draw() 호출" << std::endl;
    }

}

namespace Audio {
    void draw() {
        std::cout << "Audio::draw() 호출" << std::endl;
    }
} 

int main() {

    Graphics::draw();   // Graphics 네임스페이스의 draw 함수
    Audio::draw();   // Audio 네임스페이스의 draw 함수

    return 0;
}
