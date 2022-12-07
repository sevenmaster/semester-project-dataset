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

set<double> ins(set<double> num, double val) {
    num.insert(val);
    return num;
}

set<double> D(set<double> num, double val) {
    return ins(num, val - 5.76);
}

set<double> C(set<double> num, double val) {
    return D(num, val * 2.96);
}

set<double> B(set<double> num, double val) {
    return C(num, val + 1.34);
}

set<double> A(set<double> num, double val) {
    return B(num, val / 2.29);
}

int main() {
    double val = nolibrand();
    set<double> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}

