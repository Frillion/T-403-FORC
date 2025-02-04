#include <iostream>

int main (int argc, char *argv[]) {
    long long a,b,c;
    long long result;
    long long decimals;
    long double leftover;
    std::cin >> a >> b >> c;
    result = a*b;
    leftover = result/c;
    leftover = (a*b)%c;
    leftover /= c;
    decimals = leftover * 1e18;
    result /= c;
    std::cout << result << '.' << decimals;
    return 0;
}
