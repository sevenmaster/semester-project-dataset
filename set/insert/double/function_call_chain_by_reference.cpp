#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (double c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(set<double>* num, double val) {
    num->insert(val);
}

void D(set<double>* num, double val) {
    ins(num, val - 5.74);
}

void C(set<double>* num, double val) {
    D(num, val + 1.93);
}

void B(set<double>* num, double val) {
    C(num, val + 9.1);
}

void A(set<double>* num, double val) {
    B(num, val / 2.0);
}

int main() {
    double val = nolibrand() / 1.4;
    set<double> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}

