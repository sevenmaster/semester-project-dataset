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

int main() {
    int it = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        double a = i;
        double b = it;
        double c = a / 2.01 + b + 12.1;
        num.push_back(c);
    }
    prevent_opt(&num);
    return 0;
}
