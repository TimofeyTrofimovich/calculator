int bitwiseNot(int a) {
    return ~a;
}
int bitwiseAnd(int a, int b) {
    return a & b;
}
int bitwiseOr(int a, int b) {
    return a | b;
}
int bitwiseExclusiveOr(int a, int b) {
    return a ^ b;
}
int bitwiseConjuctionNegation(int a, int b) {
    return ~(a & b);
}
int bitwiseDisjunctionNegation(int a, int b) {
    return ~(a | b);
}
int leftShift(int number, int shift, bool isLogic) {
    if (isLogic) return number << shift;
    else for (size_t i = 0; i < shift; i++) number *= 2; return number;
}
int rightShift(int number, int shift, bool isLogic) {
    if (isLogic) return number >> shift;
    else for (size_t i = 0; i < shift; i++) number /= 2; return number;
}