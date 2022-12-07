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


int main() {
    set<int> s;
    prevent_opt(&s);
    s.erase(1);
    prevent_opt(&s);
    return 0;
}
