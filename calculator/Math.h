#pragma once
#include <stack>
#include "arithmeticFunctions.h"
#include "mathFunctions.h"
#include "trigonometricFunctions.h"
#include "Expression.h"
#include "logicalFunctions.h"
#include "bitwiseFunctions.h"
#include <iostream>

class Math {
public:
	static bool math(std::stack<Expression>&, std::stack<Expression>&, Expression&);
};

