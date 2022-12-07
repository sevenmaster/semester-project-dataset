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

void __attribute__ ((noinline)) sink(double val) {
    printf("%f", val);
}

void ins(vector<double>* num) {
    int val = num->at(1);
    sink(val);
}

int main() {
    vector<double> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

