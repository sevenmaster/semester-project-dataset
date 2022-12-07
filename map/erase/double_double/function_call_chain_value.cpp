#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, double>* num) {
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

map<double, double> ins(map<double, double> num, const double key, const double value) {
    num.erase(key);
    return num;
}

map<double, double> D(map<double, double> num, const double key, double value) {
    return ins(num, key / 2.6, value / 2.2);
}

map<double, double> C(map<double, double> num, const double key, double value) {
    return D(num, key + 2.6, value + 2.2);
}

map<double, double> B(map<double, double> num, const double key, double value) {
    return C(num, key * 2.6, value * 2.2);
}

map<double, double> A(map<double, double> num, const double key, double value) {
    return B(num, key + 1.6, value + 1.2);
}

int main() {
    // init
    map<double, double> m;
    prevent_opt(&m);
    m = A(m, 14.14, 13.37);
    prevent_opt(&m);
    return 0;
}

