#include <iostream>
#include <ostream>

int main (int argc, char *argv[]) {
    int n;    
    std::cin >> n;
    for(int i = n;i > 0;i--){
        std::cout << i << std::endl;
    }
    return 0;
}
