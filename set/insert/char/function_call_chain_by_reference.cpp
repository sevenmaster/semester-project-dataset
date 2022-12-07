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

void ins(set<char>* num, char val) {
    num->insert(val);
}

void D(set<char>* num, char val) {
    ins(num, val - 5);
}

void C(set<char>* num, char val) {
    D(num, val + 1);
}

void B(set<char>* num, char val) {
    C(num, val + 9);
}

void A(set<char>* num, char val) {
    B(num, val / 2);
}

int main() {
    int val = nolibrand();
    set<char> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}

