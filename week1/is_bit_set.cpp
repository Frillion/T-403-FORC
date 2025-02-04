#include <iostream>

bool is_bit_set(unsigned char byte, int place){
    unsigned char tester = 1 << place;
    if(tester & byte){
        return true;
    }
    return false;
}

int main (int argc, char *argv[]) {
    char character;
    unsigned int place;
    bool set;
    std::cin >> character >> place;
    if(place > (sizeof(character)*8) - 1){
        std::cout << "Bit check out of range\n";
        return 1;
    }
    set = is_bit_set(character,place);
    if(set){
        std::cout << "Bit is set\n";
    }
    else{
        std::cout << "Bit not set\n";
    }

    return 0;
}
