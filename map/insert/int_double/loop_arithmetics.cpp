#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, double>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 2.0));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    // init
    map<int, double> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
        m.insert(make_pair((j / 7 + 8) * 9, (j / 7.6 + 8.6) * 9.6));
    }
    prevent_opt(&m);
    return 0;
}

