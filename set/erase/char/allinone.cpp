#include <iostream>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;


void __attribute__ ((noinline)) prevent_opt(set <char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (char c : *num) {
        cout << c << endl;
    }
}


int main() {
    set<char> s;
    prevent_opt(&s);
    s.erase('a');
    prevent_opt(&s);
    return 0;
}
