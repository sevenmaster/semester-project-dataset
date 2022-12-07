#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(set <double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (double c : *num) {
        cout << c << endl;
    }
}

void ins(set<double>* num) {
    num->insert(13.37);
}

int main() {
    set<double> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

