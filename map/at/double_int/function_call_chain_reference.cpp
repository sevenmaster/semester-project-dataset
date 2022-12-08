#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(int val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, int>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 2));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<double, int>* num, const double key, const int value) {
	sink((*num).at(key));
}

void D(map<double, int>* num, const double key, int value) {
    ins(num, key / 2.1, value / 2);
}

void C(map<double, int>* num, const double key, int value) {
    D(num, key + 2.1, value + 2);
}

void B(map<double, int>* num, const double key, int value) {
    C(num, key * 2.1, value * 2);
}

void A(map<double, int>* num, const double key, int value) {
    B(num, key + 1.1, value + 1);
}

int main() {
    map<double, int> m;
    prevent_opt(&m);
    A(&m, 14.14, 1);
    prevent_opt(&m);
    return 0;
}

