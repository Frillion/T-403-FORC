#include <iostream>
int main (int argc, char *argv[]) {
    int a, b;
    std::cin >> a >> b;

    int c = a+b;
    std::cout << a << "\n" << b << "\n" << c << "\n";
    std::cout << "a is " << sizeof(a)*8 << " bits in size";
    return 0;
}
