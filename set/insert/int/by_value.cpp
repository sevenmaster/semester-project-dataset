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

set<int> ins(set<int> num) {
    num.insert(1);
    return num;
}

int main() {
    set<int> num;
    prevent_opt(&num);
    ins(num);
    prevent_opt(&num);
    return 0;
}
