#include <iostream>

using std::cin;
using std::cout;

size_t strlen(const char* str);
int strcmp(const char* lhs, const char* rhs);
char *strcpy(char* dest, const char* src);
char *strcat(char* dest, const char* src);

char str_a[1024];
char str_b[1024];
char str_c[2048] = "\0UNASSIGNED";
int main() {
    cin >> str_a;
    cin >> str_b;
    
    cout << "First string: " << str_a << '\n';
    cout << "Second string: " << str_b << '\n';
    cout << "Length of first string: " << strlen(str_a) << '\n';
    cout << "Length of second string: " << strlen(str_b) << '\n';
    cout << "Comparison of strings: " << strcmp(str_a, str_b) << '\n';
    char* strcpy_res = strcpy(str_c, str_a);
    cout << "Return value of strcpy ";
    if (strcpy_res != str_c) cout << "incorrect";
    else cout << "correct";
    cout << '\n';
    cout << "Copy of first: " << strcpy_res << '\n';
    char* strcat_res = strcat(str_c, str_b);
    cout << "Return value of strcat ";
    if (strcat_res != str_c) cout << "incorrect";
    else cout << "correct";
    cout << '\n';
    cout << "Copy concatenated with second: " << strcat_res << '\n';

    return 0;
}
