#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, double>* num) {
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

void ins(map<int, double>* num, const int key, const double value) {
	sink((*num).at(key));
}

void D(map<int, double>* num, const int key, double value) {
    ins(num, key / 2, value / 2.2);
}

void C(map<int, double>* num, const int key, double value) {
    D(num, key + 2, value + 2.2);
}

void B(map<int, double>* num, const int key, double value) {
    C(num, key * 2, value * 2.2);
}

void A(map<int, double>* num, const int key, double value) {
    B(num, key + 1, value + 1.2);
}

int main() {
    map<int, double> m;
    prevent_opt(&m);
    A(&m, 2, 13.37);
    prevent_opt(&m);
    return 0;
}

