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

string __attribute__ ((noinline)) randStr() {
    return to_string(rand());
}

int main() {
    int it = nolibrand();
    set<string> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        num.erase(randStr());
    }
    prevent_opt(&num);
    return 0;
}

