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

int getPriority(char);
bool math(std::stack<Expression>&, std::stack<Expression>&, Expression&);


int main()
{

    std::cout << "Calculator\n";
    std::cout << "Enter the expression: \n";
    double value;
    char ch;
    bool flag = true;
    std::stack <Expression> numbers;
    std::stack <Expression> operations;
    Expression item;

    while (true) {

        ch = std::cin.peek();       //check the next symbol but not read it
        if (ch == '\n') {
            break;
        }
        else if (ch == ' ') {
            std::cin.ignore();
            continue;
        }
        else if (((ch >= '0') && (ch <= '9')) || ((ch == '-') && (flag == true))) {        //for numbers
            std::cin >> value;
            item.type = '0';
            item.value = value;
            numbers.push(item);
            flag = false;
            continue;
        }
        else if ((ch == '+') || ((ch == '-') && (flag == 0)) || (ch == '*') || (ch == '/')) {     //for operations
            if (operations.empty()) {
                item.type = ch;
                item.value = 0;
                operations.push(item);
                std::cin.ignore();
                continue;
            }
            else if (!operations.empty() && (getPriority(ch) > getPriority(operations.top().type))) {
                item.type = ch;
                item.value = 0;
                operations.push(item);
                std::cin.ignore();
                continue;
            }
            else if (!operations.empty() && (getPriority(ch) <= getPriority(operations.top().type))) {
                if (math(numbers, operations, item) == false) {
                    system("pause");
                    return 0;
                }
                continue;
            }
        }

        else if (ch == '(') {
            item.type = ch;
            item.value = 0;
            operations.push(item);
            std::cin.ignore();
            continue;
        }
        else if (ch == ')') {
            while (operations.top().type != '(') {
                if (math(numbers, operations, item) == false) {
                    system("pause");
                    return 0;
                }
            }
            operations.pop();
            std::cin.ignore();
            continue;
        }
        else {
            std::cout << "\nwrong expression\n";
            system("pause");
            return 0;
        }
    }
    while (!operations.empty())
    {
        if (math(numbers, operations, item) == false) {
            system("pause");
            return 0;
        }
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
            operations.pop();
            break;

        case '-':
            num2 = numbers.top().value;
            numbers.pop();
            result = num2 - num1;
            item.type = '0';
            item.value = result;
            numbers.push(item);
            operations.pop();
            break;

        case '*':
            num2 = numbers.top().value;
            numbers.pop();
            result = num1 * num2;
            item.type = '0';
            item.value = result;
            numbers.push(item);
            operations.pop();
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
            operations.pop();
            break;
        default:
            std::cerr << "unexpected expression";
            return false;
    }
    return true;
}

int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    else {
        return 0;
    }
}


