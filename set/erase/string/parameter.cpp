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

void ins(set<string>* num, string val) {
    num->erase(val);
}

int main() {
    string val = to_string(nolibrand());
    set<string> num;
    prevent_opt(&num);
    ins(&num, val);
    prevent_opt(&num);
    return 0;
}

