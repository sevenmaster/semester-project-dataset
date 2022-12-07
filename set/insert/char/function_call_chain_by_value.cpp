#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (char c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

set<char> ins(set<char> num, char val) {
    num.insert(val);
    return num;
}

set<char> D(set<char> num, char val) {
    return ins(num, val - 5);
}

set<char> C(set<char> num, char val) {
    return D(num, val * 2);
}

set<char> B(set<char> num, char val) {
    return C(num, val + 1);
}

set<char> A(set<char> num, char val) {
    return B(num, val / 2);
}

int main() {
    char val = nolibrand();
    set<char> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}

