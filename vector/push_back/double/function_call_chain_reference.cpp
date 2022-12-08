#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(vector<double>* num, double val) {
    num->push_back(val);
}

void D(vector<double>* num, double val) {
    ins(num, val - 5.12);
}

void C(vector<double>* num, double val) {
    D(num, val * 2.2);
}

void B(vector<double>* num, double val) {
    C(num, val + 1.9);
}

void A(vector<double>* num, double val) {
    B(num, val / 0.51);
}

int main() {
    double val = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}


