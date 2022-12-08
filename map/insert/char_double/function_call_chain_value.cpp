#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, double>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 2.0));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<char, double> ins(map<char, double> num, const char key, const double value) {
    num[key] = value;
    return num;
}

map<char, double> D(map<char, double> num, const char key, double value) {
    return ins(num, key / 2, value / 2.2);
}

map<char, double> C(map<char, double> num, const char key, double value) {
    return D(num, key + 2, value + 2.2);
}

map<char, double> B(map<char, double> num, const char key, double value) {
    return C(num, key * 2, value * 2.2);
}

map<char, double> A(map<char, double> num, const char key, double value) {
    return B(num, key + 1, value + 1.2);
}

int main() {
    map<char, double> m;
    prevent_opt(&m);
    m = A(m, 'a', 13.37);
    prevent_opt(&m);
    return 0;
}

