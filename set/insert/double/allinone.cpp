#include <iostream>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;


void __attribute__ ((noinline)) prevent_opt(set <double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(i);
    }
    for (double c : *num) {
        cout << c << endl;
    }
}


int main() {
    set<double> s;
    prevent_opt(&s);
    s.insert(13.37);
    prevent_opt(&s);
    return 0;
}
