#include <iostream>
#include <set>
#include <cstdlib>
#include <random>

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
    set<int> s;
    prevent_opt(&s);
    for (int i = 0; i < it; i++) {
        s.insert(1 + i);
    }
    prevent_opt(&s);
    return 0;
}
