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

int main() {
    int it = nolibrand();
    set<int> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        int a = i + it - it / 2 - 2;
        num.insert(a);
    }
    prevent_opt(&num);
    return 0;
}

