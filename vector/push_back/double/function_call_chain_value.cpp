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
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

vector<double> ins(vector<double> num, double val) {
    num.push_back(val);
    return num;
}

vector<double> D(vector<double> num, double val) {
    return ins(num, val - 5.84);
}

vector<double> C(vector<double> num, double val) {
    return D(num, val * 2.6);
}

vector<double> B(vector<double> num, double val) {
    return C(num, val + 1.3);
}

vector<double> A(vector<double> num, double val) {
    return B(num, val / 2.3);
}

int main() {
    double val = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}


