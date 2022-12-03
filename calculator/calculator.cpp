// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <string>
#include "inputOutputFunctions.h"*/


#include <iostream>
#include <stack>

struct Expression {

    char type;      //0 for numbers, "+" for addiction operation and so on
    double value;

};


bool math(std::stack<Expression>&, std::stack<Expression>&, Expression&);


int main()
{
    double value;
    char ch;
    std::stack <Expression> numbers;
    std::stack <Expression> operations;
    Expression item;

    while (true) {
        ch = std::cin.peek();       //check the next symbol but not read it
        if (ch == '\n') {
            break;
        }
        if (ch >= '0' && ch < '9') {        //for numbers
            std::cin >> value;
            item.type = '0';
            item.value = value;
            numbers.push(item);
            continue;
        }
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {     //for operations
            item.type = ch;
            item.value = 0;
            operations.push(item);
        }
        std::cin.ignore();
    }
    if (math(numbers, operations, item) == false) {
        system("pause");
        return 0;
    }
    std::cout << numbers.top().value << std::endl;
    return 0;
}


bool math(std::stack<Expression>& numbers, std::stack<Expression>& operations, Expression& item) {
    double num1;
    double num2;
    double result;
    num1 = numbers.top().value;
    numbers.pop();
    switch (operations.top().type) {
        case '+' : 
            num2 = numbers.top().value;
            numbers.pop();
            result = num1 + num2; 
            item.type = '0';
            item.value = result;
            numbers.push(item);
            break;

        case '-':
            num2 = numbers.top().value;
            numbers.pop();
            result = num2 - num1;
            item.type = '0';
            item.value = result;
            numbers.push(item);
            break;

        case '*':
            num2 = numbers.top().value;
            numbers.pop();
            result = num1 * num2;
            item.type = '0';
            item.value = result;
            numbers.push(item);
            break;

        case '/':
            num2 = numbers.top().value;
            if (num1 == 0) {
                std::cerr << "\nerror (divison by zero)\n";
                return false;
            }
            numbers.pop();
            result = num2 / num1;
            item.type = '0';
            item.value = result;
            numbers.push(item);
            break;
        default:
            std::cerr << "unexpected expression";
            return false;
    }
    return true;
}


