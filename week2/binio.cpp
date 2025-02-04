#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>

using std::cin;
using std::cout;
using std::ofstream;
using std::ifstream;

int main (int argc, char *argv[]) {
    int num_strings = 0;
    int word_size;
    int count;
    char command;
    char buff[256];
    ofstream outfile;
    ifstream infile;


    infile.open("words.bin", std::ios::binary);
    if(!infile.is_open()){
        cout << "Could not find previously saved words, writes will create a new one\n";
    }
    else{
        infile.seekg(0,std::ios::beg);
        infile.read(reinterpret_cast<char *>(&num_strings), sizeof(num_strings));
    }
    infile.close();


    while (1) {
        count = 0;
        cout << "choose an action:\n";
        cout << "Write word to file(w)\n";
        cout << "Read words from file(r)\n";
        cout << "quit(q)\n";
        cin >> command;
        switch (command) {
            case 'w':
                // This little snipped was added to create the file in case it doesnt exist
                // Its required becuase the other open() for write has ios::in to avoid truncate
                infile.open("words.bin"); 
                if(!infile.is_open()){
                    outfile.open("words.bin");
                    outfile.close();
                }
                infile.close();

                //In is needed here to append to the binary file otherwise it will truncate with binary/out
                outfile.open("words.bin", std::ios::binary | std::ios::ate | std::ios::in);
                cout << "What word would you like written: ";
                cin >> buff;
                cout << "\n";
                num_strings++;
                word_size = strlen(buff);
                outfile.seekp(0, std::ios::beg);
                outfile.write(reinterpret_cast<char *>(&num_strings), sizeof(num_strings));
                outfile.seekp(0, std::ios::end);
                outfile.write(reinterpret_cast<char *>(&word_size), sizeof(word_size));
                outfile.write(buff, sizeof(buff));
                outfile.close();
                break; 
            case 'r':
                infile.open("words.bin", std::ios::binary);
                if(!infile.is_open()){
                    cout << "File could not be opened, might not exist please write first.\n";
                    break;
                }
                infile.seekg(sizeof(num_strings),std::ios::beg);
                infile.seekg(sizeof(word_size),std::ios::cur);
                while(infile.read(buff, sizeof(buff))){
                    cout << "Word " << count << ": " << buff << "\n";
                    count++;
                    infile.seekg(sizeof(word_size),std::ios::cur);
                }
                infile.close();
                break;
            case 'q':
                exit(0);
            default:
                cout << command << " - not a command that can be run\n";
        }
    } 
    return 0;
}
