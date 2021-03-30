// Copyright [2021] <Nikita Semaev>
#include <string>
#include <iostream>
#include "../include/MyStack.h"
#include "../include/postfix.h"

std::int8_t priority(char op) {
    std::int8_t result = -1;
    if (op == '(') {
        result = 0;
    } else if (op == ')') {
        result = 1;
    } else if (op == '+' || op == '-') {
        result = 2;
    } else if (op == '*' || op == '/') {
        result = 3;
    }
    return result;
}

std::string infix2postfix(std::string infix) {
    std::string postfix;
    MyStack <char> stack;
    std::string operand;
    for (std::size_t i = 0; i < infix.size(); ++i) {
        if (priority(infix[i]) >= 0) {
            if (!operand.empty()) {
                postfix.append(operand + ' ');
                operand.clear();
            }
            if (priority(infix[i]) > 0) {
                while (!stack.isEmpty()
                        && priority(stack.getHead()) >= priority(infix[i])) {
                    postfix.append(std::string() + stack.pop() + ' ');
                }
            }
            if (priority(infix[i]) != 1) {
                stack.push(infix[i]);
            } else {
                stack.pop();
            }
        } else if (infix[i] == ' ') {
            if (!operand.empty()) {
                postfix.append(operand + ' ');
                operand.clear();
            }
        } else {
            operand += infix[i];
            if (i == (infix.size() - 1)) {
                postfix.append(operand + ' ');
                operand.clear();
            }
        }
    }
    while (!stack.isEmpty()) {
        postfix.append(std::string() + stack.pop() + ' ');
    }
    if (postfix[postfix.size() - 1] == ' ') {
        postfix.pop_back();
    }
    return postfix;
}
