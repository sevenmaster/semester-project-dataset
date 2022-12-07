#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<double, char>* num, const double key, const char val) {
    (*num)[key] = val;
}

int main() {
    // init
    map<double, char> m;
    prevent_opt(&m);
    ins(&m, 14.14, 'c');
    prevent_opt(&m);
    return 0;
}
