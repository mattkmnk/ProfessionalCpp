#include <iostream>
#include <string>


int main() {
    std::string str = "1011";
    int res = std::stoi(str, nullptr, 2);
    std::cout << res << '\n';

    std::string str2 = R"(Line 1
    Line 2)"; //Raw String
    std::cout << str2 << '\n';

    std::string str3 = R"---(Testing something "(out)")---"; //"---(string)---" => --- is a delimiter
    std::cout << str3 << '\n';
}
