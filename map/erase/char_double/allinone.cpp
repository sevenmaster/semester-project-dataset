#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, double>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 2.0));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}


int main() {
    // init
    map<char, double> m;
    prevent_opt(&m);
    m.erase('a');
    prevent_opt(&m);
    return 0;
}

