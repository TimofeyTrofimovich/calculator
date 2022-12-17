#include "Math.h"
bool Math::math(std::stack<Expression>& numbers, std::stack<Expression>& operations, Expression& item) {
    double num1;
    double num2;
    double result;
    num1 = numbers.top().value;
    numbers.pop();
    switch (operations.top().type) {
    case '+':
        num2 = numbers.top().value;
        numbers.pop();
        result = sum(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;

    case '-':
        num2 = numbers.top().value;
        numbers.pop();
        result = sub(num2, num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;

    case '*':
        num2 = numbers.top().value;
        numbers.pop();
        result = mult(num1, num2);
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
        result = division(num2, num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case '%':
        num2 = numbers.top().value;
        if (num1 == 0) {
            std::cerr << "\nerror (divison by zero)\n";
            return false;
        }
        numbers.pop();
        result = mod(num2, num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case '^':
        num2 = numbers.top().value;
        numbers.pop();
        result = pow(num2, num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case '!':
        result = factorial(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;

    case 'q':
        if (num1 < 0) {
            std::cerr << "can't take square root from a negative number";
            return false;
        }
        result = sqrt_(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 's':
        result = Sin(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'c':
        result = Cos(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 't':
        if (Cos(num1) == 0) {
            std::cerr << "incorrect argument for tangens";
            return false;
        }
        result = tan(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'g':
        if (Sin(num1) == 0) {
            std::cerr << "incorrect argument for cotangens";
            return false;
        }
        result = cot(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'e':
        result = exp(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'N':
        result = negation(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'W':
        result = bitwiseNot(num1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'A':
        num2 = numbers.top().value;
        numbers.pop();
        result = conjuction(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'O':
        num2 = numbers.top().value;
        numbers.pop();
        result = disjunction(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'X':
        num2 = numbers.top().value;
        numbers.pop();
        result = exclusiveOr(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'Z':
        num2 = numbers.top().value;
        numbers.pop();
        result = conjuctionNegation(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'Y':
        num2 = numbers.top().value;
        numbers.pop();
        result = disjunctionNegation(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'V':
        num2 = numbers.top().value;
        numbers.pop();
        result = bitwiseAnd(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'U':
        num2 = numbers.top().value;
        numbers.pop();
        result = bitwiseOr(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'T':
        num2 = numbers.top().value;
        numbers.pop();
        result = bitwiseExclusiveOr(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'S':
        num2 = numbers.top().value;
        numbers.pop();
        result = bitwiseConjuctionNegation(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'R':
        num2 = numbers.top().value;
        numbers.pop();
        result = bitwiseDisjunctionNegation(num1, num2);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'Q':
        num2 = numbers.top().value;
        numbers.pop();
        result = leftShift(num2, num1, 1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'P':
        num2 = numbers.top().value;
        numbers.pop();
        result = rightShift(num2, num1, 1);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'M':
        num2 = numbers.top().value;
        numbers.pop();
        result = leftShift(num2, num1, 0);
        item.type = '0';
        item.value = result;
        numbers.push(item);
        operations.pop();
        break;
    case 'L':
        num2 = numbers.top().value;
        numbers.pop();
        result = rightShift(num2, num1, 0);
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

