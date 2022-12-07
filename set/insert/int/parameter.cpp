#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <int>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (int c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(set<int>* num, int val) {
    num->insert(val);
}

int main() {
    int val = nolibrand();
    set<int> num;
    prevent_opt(&num);
    ins(&num, val);
    prevent_opt(&num);
    return 0;
}

