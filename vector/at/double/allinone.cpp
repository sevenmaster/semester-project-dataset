#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<double>* num, double val) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    double a = num->at(rand());
    printf("%f %f", a, val);
}

int main() {
    vector<double> num;
    double val = 1.62;
    prevent_opt(&num, val);
    val = num.at(1);
    prevent_opt(&num, val);
    return 0;
}

