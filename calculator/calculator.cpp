// calculator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*#include <iostream>
#include <string>
#include "inputOutputFunctions.h"*/


#include <iostream>
#include "Math.h"


int getPriority(char);



int main()
{
    Math obj();
    std::cout << "Calculator\n";
    std::cout << "Enter the expression: \n";
    std::cout << "use these expressions:\nsin - sinus\ncos - cosinus\ntan - tangens\ncot  - cotangens\np - 3.14\nexp(n) - e^n\n";
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
        else if (ch == 'p') {
            item.type = '0';
            item.value = PI;
            numbers.push(item);
            flag = false;
            std::cin.ignore();
            continue;
        }
        else if ((ch == '+') || ((ch == '-') && (flag == 0)) || (ch == '*') || (ch == '/') || (ch == '^') || (ch == '%')) {     //for operations
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
                if (Math::math(numbers, operations, item) == false) {
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
                if (Math::math(numbers, operations, item) == false) {
                    system("pause");
                    return 0;
                }
            }
            operations.pop();
            std::cin.ignore();
            continue;
        }
        else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'e') {
            char arr[3];
            for (int i=0; i < 3; i++) {
                ch = std::cin.peek();
                arr[i] = ch;
                std::cin.ignore();
            }
            if (arr[0] == 's' && arr[1] == 'i' && arr[2] == 'n') {
                item.type = 's';
                item.value = 0;
                operations.push(item);
                continue;
            }
            else if (arr[0] == 'c' && arr[1] == 'o' && arr[2] == 's') {
                item.type = 'c';
                item.value = 0;
                operations.push(item);
                continue;
            }
            else if (arr[0] == 't' && arr[1] == 'a' && arr[2] == 'n') {
                item.type = 't';
                item.value = 0;
                operations.push(item);
                continue;
            }
            else if (arr[0] == 'c' && arr[1] == 'o' && arr[2] == 't') {
                item.type = 'g';
                item.value = 0;
                operations.push(item);
                continue;
            }
            else if (arr[0] == 's' && arr[1] == 'q' && arr[2] == 'r') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 't') {
                    item.type = 'q';
                    item.value = 0;
                    operations.push(item);
                    continue;
                }
            }
        }

        else {
            std::cout << "\nwrong expression\n";
            system("pause");
            return 0;
        }
    }
    while (!operations.empty())
    {
        if (Math::math(numbers, operations, item) == false) {
            system("pause");
            return 0;
        }
    }
    std::cout << numbers.top().value << std::endl;
    return 0;
}




int getPriority(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    }
    else if (ch == '*' || ch == '/' || ch == '%') {
        return 2;
    }
    else if (ch == '^' || ch == 'q') {
        return 3;
    }
    else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'e') {
        return 4;
    }
    else {
        return 0;
    }
}



