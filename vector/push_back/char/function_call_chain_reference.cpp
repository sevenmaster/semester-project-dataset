#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(vector<char>* num, char val) {
    num->push_back(val);
}

void D(vector<char>* num, char val) {
    ins(num, val - 5);
}

void C(vector<char>* num, char val) {
    D(num, val + 1);
}

void B(vector<char>* num, char val) {
    C(num, val + 9);
}

void A(vector<char>* num, char val) {
    B(num, val / 2);
}

int main() {
    int val = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}


