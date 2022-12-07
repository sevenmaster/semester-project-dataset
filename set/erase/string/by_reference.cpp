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

void ins(set<string>* num) {
    num->erase("Hello World");
}

int main() {
    set<string> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

