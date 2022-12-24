#include "Calculator.h"

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
    else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'e' || ch == 'A' || ch == 'L' || ch == 'M' 
        || ch == 'N' || ch == 'O' || ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S' || ch == 'T'
        || ch == 'U' || ch == 'V' || ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') {
        return 4;
    }
    else if (ch == '|' || ch == '!') {
        return 5;
    }
    else {
        return 0;
    }
}

int Calculator::calculate() {
    double value;
    char ch;
    bool flag = true;
    bool module = false;
    std::stack <Expression> numbers;
    std::stack <Expression> operations;
    Expression item;
    std::cout << "Calculator\n";
    std::cout << "use these expressions:\n" << "trigonometrical:\n"
        "sin - sine \t \t cos - cosine\ntan - tangent \t \t " << "cot  - cotangent\np - 3.14\n\n" <<
        "scientific:\n" << "exp(n) - e^n \t \t |n| - absolute value of n\n\n" << "logical:\n" <<
        "NOT - negation \t \t \t AND - conjunction\nOR - disjunction \t \t XOR - exclusive disjunction\n" <<
        "NAND - conjunction negation \t NOR - disjunction negation\n\n" << "bitwise:\n" <<
        "BNOT - bitwise negation \t \t BAND - bitwise conjunction\nBOR - bitwise disjunction \t \t BXOR - bitwise exclusive disjunction\n" <<
        "BNAN - bitwise conjuction negation \t BNOR - bitwise disjunction negation\nBLS-bitwise left shift \t \t \t " <<
        "BRS - bitwise right shift\nBALS - bitwise arithmetic left shift \t BARS - bitwise arithmetic right shift\n\n";
    std::cout << "Enter the expression: \n";
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
            item.value = 3.14159;
            numbers.push(item);
            flag = false;
            std::cin.ignore();
            continue;
        }
        else if ((ch == '+') || ((ch == '-') && (flag == 0)) || (ch == '*') || (ch == '/') || (ch == '^') || (ch == '%') || (ch == '!')) {     //for operations
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
        else if (ch == '|') {
            if (module == false) {
                item.type = ch;
                item.value = 0;
                operations.push(item);
                std::cin.ignore();
                module = true;
                continue;
                
            }
            else {
                while (operations.top().type != '|') {
                    if (Math::math(numbers, operations, item) == false) {
                        system("pause");
                        return 0;
                    }
                }
                numbers.top().value = absolute(numbers.top().value);
                operations.pop();
                std::cin.ignore();
                module = false;

                continue;
            }
        }
        else if (ch == 'O') {
            char arr[2];
            for (size_t i = 0; i < 2; i++)
            {
                ch = std::cin.peek();
                arr[i] = ch;
                std::cin.ignore();
            }
            if (arr[0] == 'O' && arr[1] == 'R') {
                item.type = 'O';
                item.value = 0;
                operations.push(item);
            }
        }
        else if (ch == 's' || ch == 'c' || ch == 't' || ch == 'e' || ch == 'A' || ch == 'X' || ch == 'N' || ch == 'B') {
            char arr[3];
            for (int i = 0; i < 3; i++) {
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
            else if (arr[0] = 'N' && arr[1] == 'O' && arr[2] == 'T') {
                item.type = 'N';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'A' && arr[1] == 'N' && arr[2] == 'D') {
                item.type = 'A';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'X' && arr[1] == 'O' && arr[2] == 'R') {
                item.type = 'X';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'N' && arr[1] == 'O' && arr[2] == 'R') {
                item.type = 'Y';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'N' && arr[1] == 'A' && arr[2] == 'N') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'D') {
                    item.type = 'Z';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'N' && arr[2] == 'O') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'T') {
                    item.type = 'W';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'A' && arr[2] == 'N') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'D') {
                    item.type = 'V';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'O' && arr[2] == 'R') {
                    item.type = 'U';
                    item.value = 0;
                    operations.push(item);
            }
            else if (arr[0] = 'B' && arr[1] == 'X' && arr[2] == 'O') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'R') {
                    item.type = 'T';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'N' && arr[2] == 'A') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'N') {
                    item.type = 'S';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'N' && arr[2] == 'O') {
                ch = std::cin.peek();
                std::cin.ignore();
                if (ch == 'R') {
                    item.type = 'R';
                    item.value = 0;
                    operations.push(item);
                }
            }
            else if (arr[0] = 'B' && arr[1] == 'L' && arr[2] == 'S') {
                item.type = 'Q';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'B' && arr[1] == 'R' && arr[2] == 'S') {
                item.type = 'P';
                item.value = 0;
                operations.push(item);
            }
            else if (arr[0] = 'B' && arr[1] == 'A' && arr[2] == 'L') {
            ch = std::cin.peek();
            std::cin.ignore();
            if (ch == 'S') {
                item.type = 'M';
                item.value = 0;
                operations.push(item);
            }
            }
            else if (arr[0] = 'B' && arr[1] == 'A' && arr[2] == 'R') {
            ch = std::cin.peek();
            std::cin.ignore();
            if (ch == 'S') {
                item.type = 'L';
                item.value = 0;
                operations.push(item);
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
}