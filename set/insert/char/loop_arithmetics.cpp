#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (char c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    set<char> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        char a = i + it - it / 2 - 2;
        num.insert(a);
    }
    prevent_opt(&num);
    return 0;
}

