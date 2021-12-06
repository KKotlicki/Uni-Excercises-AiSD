// Zadanie: Kalkulator
// Autor: Konrad Kotlicki
// Nr indeksu: 310958

#include <iostream>
#include <stack>
#include <string>

int main(){
    bool is_error = false;
    bool is_last_symbol_a_digit = false;

    // Stacks of digits and operators
    char single_operator;
    double digit_left, digit_right;
    std::stack<double> digits;
    std::stack<char> operators;

    // Inputs
    std::string input_stream;
    std::getline(std::cin, input_stream);

    // Calculations using Edsger Dijkstra algorithm
    for(char& input_symbol: input_stream){
        // Check if input symbol is a number
        if ('0'<=input_symbol && input_symbol<='9')
            {
                if(is_last_symbol_a_digit)
                {
                    double number_left = digits.top();
                    digits.pop();
                    digits.push(number_left * 10 + input_symbol - '0');
                }
                else digits.push(input_symbol-'0');
                is_last_symbol_a_digit = true;
                continue;
            }

        is_last_symbol_a_digit = false;

        // Check if input symbol is an operator
        if (input_symbol=='/' || input_symbol=='*' || input_symbol=='+' || input_symbol=='-')
            {
                operators.push(input_symbol);
                continue;
            }

        // Check if input symbol is a closing bracket
        if (input_symbol==')'){
            // Save digits and operator in temporary variables
            digit_right = (double) digits.top();
            digits.pop();
            digit_left = (double) digits.top();
            digits.pop();
            single_operator = operators.top();
            operators.pop();
            // Perform operation
            if (single_operator=='/' && digit_right==0)
                {
                    std::cout << "NaN" << std::endl;
                    is_error = true;
                    break;
                }
            if (single_operator=='/') digits.push(digit_left / digit_right);
            if (single_operator=='*') digits.push(digit_left * digit_right);
            if (single_operator=='+') digits.push(digit_left + digit_right);
            if (single_operator=='-') digits.push(digit_left - digit_right);
        }
    };
    if(!is_error) std::cout << digits.top();
    return 1;
}
