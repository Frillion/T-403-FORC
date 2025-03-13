#include <vector>
#include <iostream>

int main (int argc, char *argv[]) {
    std::vector<int> v(5,3);
    for(int& var : v) {
        var++;
    }

    for(int var : v) {
        std::cout << var << " ";
    }

    return 0;
}
