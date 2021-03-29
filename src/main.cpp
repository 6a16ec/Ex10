// Copyright [2021] <Nikita Semaev>
#include <iostream>
#include <string>

#include "../include/postfix.h"

int main() {
    std::string s1("2 + 6 * 3 / (4 - 2)");
    std::string s2 = infix2postfix(s1);
    std::cout << s2 << std::endl;  // 2 6 3 * 4 2 - / +

    std::string s3("(1 + 2) / (3 + 4 * 6.7) - 5.3 * 4.4");
    std::string s4 = infix2postfix(s3);
    std::cout << s4 << std::endl;  // 1 2 + 3 4 6.7 * + / 5.3 4.4 * -


    return 0;
}
