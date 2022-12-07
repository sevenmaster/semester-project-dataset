#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <int>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (int c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

set<int> ins(set<int> num, int val) {
    num.erase(val);
    return num;
}

set<int> D(set<int> num, int val) {
    return ins(num, val - 5);
}

set<int> C(set<int> num, int val) {
    return D(num, val * 2);
}

set<int> B(set<int> num, int val) {
    return C(num, val + 1);
}

set<int> A(set<int> num, int val) {
    return B(num, val / 2);
}

int main() {
    int val = nolibrand();
    set<int> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}

