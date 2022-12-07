#include <string>
#include <iostream>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;


void __attribute__ ((noinline)) prevent_opt(set <string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->insert(to_string(i));
    }
    for (string c : *num) {
        cout << c << endl;
    }
}


int main() {
    set<string> s;
    prevent_opt(&s);
    s.insert("Hello World");
    prevent_opt(&s);
    return 0;
}
