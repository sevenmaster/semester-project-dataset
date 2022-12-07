#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
    double a = num->at(rand());
    printf("%f", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(double val) {
    printf("%f", val);
}

int main() {
    int it = nolibrand();
    vector<double> num[it];
    prevent_opt(&num[it / 2]);
    sink(num[it / 2].at(it / 2 + 1));
    prevent_opt(&num[it / 2]);
    return 0;
}

