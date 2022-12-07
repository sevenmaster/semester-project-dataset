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

vector<double> ins(vector<double> num, int pos) {
    sink(num.at(pos));
    return num;
}

vector<double> D(vector<double> num, int pos) {
    return ins(num, pos - 5);
}

vector<double> C(vector<double> num, int pos) {
    return D(num, pos * 2);
}

vector<double> B(vector<double> num, int pos) {
    return C(num, pos + 1);
}

vector<double> A(vector<double> num, int pos) {
    return B(num, pos / 2);
}

int main() {
    int pos = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    num = A(num, pos);
    prevent_opt(&num);
    return 0;
}

