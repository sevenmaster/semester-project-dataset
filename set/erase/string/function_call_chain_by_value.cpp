#include <string>
#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (string c : *num) {
        cout << c << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

set<string> ins(set<string> num, string val) {
    num.erase(val);
    return num;
}

set<string> D(set<string> num, string val) {
    return ins(num, val + "d");
}

set<string> C(set<string> num, string val) {
    return D(num, val + "c");
}

set<string> B(set<string> num, string val) {
    return C(num, val + "b");
}

set<string> A(set<string> num, string val) {
    return B(num, val + "a");
}

int main() {
    string val = to_string(nolibrand());
    set<string> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}

