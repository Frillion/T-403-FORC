#include "c_string_functions.h"

size_t strlen(const char* str) {
    int len = 0;
    while(str[len] != 0){
        len++;
    }
    return len;
}

int strcmp(const char* lhs, const char* rhs) {
    const char *s1 = lhs;
    const char *s2 = rhs;
    char c1,c2;
    do{
        c1 = *s1++;
        c2 = *s2++;
        if(c1 == 0){
            if(c1 - c2 < 0){
                return -1;
            }
            if(c1 - c2 > 0){
                return 1;
            }
            return 0;
        }
    }
    while(c1 == c2);

    if(c1 - c2 < 0){
        return -1;
    }
    if(c1 - c2 > 0){
        return 1;
    }
    return 0;
}

char *strcpy(char* dest, const char* src) {
    const char *sc = src;
    char *des = dest;
    while(*sc != 0){
        *des++ = *sc++;
    }
    *des = '\0';
    return dest;
}

char *strcat(char* dest, const char* src) {
    strcpy(dest+strlen(dest), src);
    return dest;
}
