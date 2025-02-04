#include <iostream>

int main (int argc, char *argv[]) {
    int kim,trump;
    std::cin >> trump >> kim;
    if(kim < trump){
        std::cout << "MAGA!";
        return 0;
    }
    if(trump < kim){
        std::cout << "FAKE NEWS!";
        return 0;
    }
    std::cout << "WORLD WAR 3!";
    return 0;
}
