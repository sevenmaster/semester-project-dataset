#include <string>
#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->erase(to_string(i));
    }
    for (string c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    set<string> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        string a = to_string(i + it - it / 2 - 2);
        num.erase(a);
    }
    prevent_opt(&num);
    return 0;
}

