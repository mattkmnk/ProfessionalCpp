#include <iostream>
#include <cstring>

char* copyString(const char* str) {
    char* result = new char[strlen(str) + 1];
    strcpy(result, str);
    return result;
}

char* appendStrings(const char* str1, const char* str2, const char* str3) {
    int size = strlen(str1) + strlen(str2) + strlen(str3) + 1;
    char* result = new char[size];
    strcpy(result, str1);
    strcat(result, str2);
    strcat(result, str3);
    return result;
}


/*int main() {

    char str[] = "Hello";
    std::cout << strlen(str);
    char* res = copyString(str);
    std::cout << '\n' << res;

}*/