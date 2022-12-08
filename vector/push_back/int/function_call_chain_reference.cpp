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

void ins(vector<int>* num, int val) {
    num->push_back(val);
}

void D(vector<int>* num, int val) {
    ins(num, val - 5);
}

void C(vector<int>* num, int val) {
    D(num, val * 2);
}

void B(vector<int>* num, int val) {
    C(num, val + 1);
}

void A(vector<int>* num, int val) {
    B(num, val / 2);
}

int main() {
    int val = nolibrand();
    vector<int> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}


