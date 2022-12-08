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

void ins(map<char, double>* num, const char key, const double value) {
    (*num)[key] = value;
}

void D(map<char, double>* num, const char key, double value) {
    ins(num, key / 2, value / 2.2);
}

void C(map<char, double>* num, const char key, double value) {
    D(num, key + 2, value + 2.2);
}

void B(map<char, double>* num, const char key, double value) {
    C(num, key * 2, value * 2.2);
}

void A(map<char, double>* num, const char key, double value) {
    B(num, key + 1, value + 1.2);
}

int main() {
    map<char, double> m;
    prevent_opt(&m);
    A(&m, 'a', 13.37);
    prevent_opt(&m);
    return 0;
}

