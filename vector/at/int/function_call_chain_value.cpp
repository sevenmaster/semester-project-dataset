#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<int>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(int val) {
    printf("%d", val);
}

vector<int> ins(vector<int> num, int pos) {
    sink(num.at(pos));
    return num;
}

vector<int> D(vector<int> num, int pos) {
    return ins(num, pos - 5);
}

vector<int> C(vector<int> num, int pos) {
    return D(num, pos * 2);
}

vector<int> B(vector<int> num, int pos) {
    return C(num, pos + 1);
}

vector<int> A(vector<int> num, int pos) {
    return B(num, pos / 2);
}

int main() {
    int pos = nolibrand();
    vector<int> num;
    prevent_opt(&num);
    num = A(num, pos);
    prevent_opt(&num);
    return 0;
}

