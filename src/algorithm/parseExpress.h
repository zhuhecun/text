//
// Created by 祝合存 on 24-10-12.
//
#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <utility>
#include <stack>

double applyOp(char op, double a, double b);
int precedence(char op);

std::pair<double, std::string> parseExpress(const std::string& input);

#endif // PARSER_H

