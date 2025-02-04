#include <cstring>
#include <fstream>
#include <iostream>

void flush(char* buff){
    char* guide = buff;
    while(*guide != 0){
        *guide = 0;
        guide++;
    }
}

int main (int argc, char *argv[]) {
    char buff[256];
    std::ofstream outfile("words.txt");
    while(1){
        std::cin >> buff;
        if (!strcmp(buff,"exit\0")){break;}
        outfile << buff;
        flush(buff);
    }
    outfile.close();
    std::ifstream infile("words.txt");
    if(!infile.is_open()){
        std::cout << "The file words.txt could not be opened";
        return 127; 
    }
    infile >> buff;
    std::cout << buff << "\n";
}
