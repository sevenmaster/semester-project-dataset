#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

vector<double> ins(vector<double> num) {
    num.at(1);
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    double a = num->at(rand());
    printf("%f", a);
}

int main() {
    vector<double> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

