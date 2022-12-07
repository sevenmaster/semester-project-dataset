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

void D(set<string>* num, string val) {
    ins(num, val + 'd');
}

void C(set<string>* num, string val) {
    D(num, val + 'c');
}

void B(set<string>* num, string val) {
    C(num, val + 'b');
}

void A(set<string>* num, string val) {
    B(num, val + 'a');
}

int main() {
    string val = to_string(nolibrand());
    set<string> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}

