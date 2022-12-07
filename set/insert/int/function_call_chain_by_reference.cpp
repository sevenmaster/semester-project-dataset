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

void ins(set<int>* num, int val) {
    num->insert(val);
}

void D(set<int>* num, int val) {
    ins(num, val - 5);
}

void C(set<int>* num, int val) {
    D(num, val + 1);
}

void B(set<int>* num, int val) {
    C(num, val + 9);
}

void A(set<int>* num, int val) {
    B(num, val / 2);
}

int main() {
    int val = nolibrand() / 1;
    set<int> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}

