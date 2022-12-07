#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    // insert a random number of elements into num
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

void ins(vector<double>* num, int pos) {
    sink(num->at(pos));
}

void D(vector<double>* num, int pos) {
    ins(num, pos - 5);
}

void C(vector<double>* num, int pos) {
    D(num, pos * 2);
}

void B(vector<double>* num, int pos) {
    C(num, pos + 1);
}

void A(vector<double>* num, int pos) {
    B(num, pos / 2);
}

int main() {
    int val = nolibrand();
    vector<double> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}
