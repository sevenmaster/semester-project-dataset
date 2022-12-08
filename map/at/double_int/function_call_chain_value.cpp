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

map<double, int> ins(map<double, int> num, const double key, const int value) {
	sink(num.at(key));
    return num;
}

map<double, int> D(map<double, int> num, const double key, int value) {
    return ins(num, key / 2.1, value / 2);
}

map<double, int> C(map<double, int> num, const double key, int value) {
    return D(num, key + 2.1, value + 2);
}

map<double, int> B(map<double, int> num, const double key, int value) {
    return C(num, key * 2.1, value * 2);
}

map<double, int> A(map<double, int> num, const double key, int value) {
    return B(num, key + 1.1, value + 1);
}

int main() {
    map<double, int> m;
    prevent_opt(&m);
    m = A(m, 14.14, 1);
    prevent_opt(&m);
    return 0;
}

