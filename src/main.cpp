#include "parseExpress.h"

int main(int argc, char* argv[])
{
    //std::string input = "1.23 + 2 * ( 1 + 2 / 5 - 4 )";
    std::string input = "1 + 2 * 3";
    double result;
    std::string res;

    std::tie(result, res) = parseExpress(input);


    //打印结果
    printf("result = %f\n", result);

    return 0;
}