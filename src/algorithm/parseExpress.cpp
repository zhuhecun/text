//
// Created by 祝合存 on 24-10-12.
//
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <utility>

// 函数用于计算两个操作数和一个操作符的结果
double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// 函数用于确定操作符的优先级
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// 函数用于从字符串中提取数字
double getNumber(const std::string& expr, size_t& pos) {
    double number = 0;
    while (isdigit(expr[pos]) || expr[pos] == '.') {
        number = number * 10 + (expr[pos] - '0');
        ++pos;
    }
    return number;
}

// 主函数用于解析表达式
std::pair<double, std::string> parseExpress(const std::string& expr) {
    std::stack<double> numbers;
    std::stack<char> ops;
    size_t pos = 0;
    double a, b;
    char op;

    while (pos < expr.size()) {
        if (isspace(expr[pos])) {
            ++pos;
        } else if (isdigit(expr[pos])) {
            numbers.push(getNumber(expr, pos));
        } else if (expr[pos] == '(') {
            ops.push(expr[pos]);
            ++pos;
        } else if (expr[pos] == ')') {
            while (!ops.empty() && ops.top() != '(') {
                b = numbers.top(); numbers.pop();
                a = numbers.top(); numbers.pop();
                op = ops.top(); ops.pop();
                numbers.push(applyOp(a, b, op));
            }
            if (!ops.empty()) ops.pop();
            ++pos;
        } else {
            while (!ops.empty() && precedence(ops.top()) >= precedence(expr[pos])) {
                b = numbers.top(); numbers.pop();
                a = numbers.top(); numbers.pop();
                op = ops.top(); ops.pop();
                numbers.push(applyOp(a, b, op));
            }
            ops.push(expr[pos]);
            ++pos;
        }
    }

    while (!ops.empty()) {
        b = numbers.top(); numbers.pop();
        a = numbers.top(); numbers.pop();
        op = ops.top(); ops.pop();
        numbers.push(applyOp(a, b, op));
    }

    return {numbers.top(), ""};
}