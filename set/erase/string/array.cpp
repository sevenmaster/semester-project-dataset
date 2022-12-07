#include <string>
#include <iostream>
#include <set>
#include <cstdlib>
#include <random>

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
    set<string> s;
    prevent_opt(&s);
    for (int i = 0; i < it; i++) {
        s.erase(to_string(i));
    }
    prevent_opt(&s);
    return 0;
}
