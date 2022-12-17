bool negation(bool a)
{
    if (a) return 0;
    else  return 1;
}

bool conjuction(bool a, bool b)
{
    return a && b;
}

bool disjunction(bool a, bool b) {
    return a || b;
}

int exclusiveOr(bool a, bool b) {
    if (a == b) return 0;
    else return 1;
}

int conjuctionNegation(bool a, bool b) {
    return negation(conjuction(a, b));
}

int disjunctionNegation(bool a, bool b) {
    return negation(disjunction(a, b));
}