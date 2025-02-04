#include <iostream>

struct a{
    int x;
    int y;
    int z;
    int w;
};

int main (int argc, char *argv[]) {
    std::cout << sizeof(a) << std::endl;
    std::cout << alignof(a) << std::endl;
    return 0;
}
