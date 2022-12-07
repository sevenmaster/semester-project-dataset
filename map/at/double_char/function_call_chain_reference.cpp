#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(char val) {
    std::cout << val << std::endl;
}


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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<double, char>* num, const double key, const char value) {
	sink((*num).at(key));
}

void D(map<double, char>* num, const double key, char value) {
    ins(num, key / 2.1, value / 'b');
}

void C(map<double, char>* num, const double key, char value) {
    D(num, key + 2.1, value + 'b');
}

void B(map<double, char>* num, const double key, char value) {
    C(num, key * 2.1, value * 'b');
}

void A(map<double, char>* num, const double key, char value) {
    B(num, key + 1.1, value + 'b');
}

int main() {
    // init
    map<double, char> m;
    prevent_opt(&m);
    A(&m, 14.14, 'c');
    prevent_opt(&m);
    return 0;
}

