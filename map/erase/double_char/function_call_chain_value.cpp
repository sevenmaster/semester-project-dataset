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

map<double, char> ins(map<double, char> num, const double key, const char value) {
	sink(num.at(key));
    return num;
}

map<double, char> D(map<double, char> num, const double key, char value) {
    return ins(num, key / 2, value / 'b');
}

map<double, char> C(map<double, char> num, const double key, char value) {
    return D(num, key + 2, value + 'b');
}

map<double, char> B(map<double, char> num, const double key, char value) {
    return C(num, key * 2, value * 'b');
}

map<double, char> A(map<double, char> num, const double key, char value) {
    return B(num, key + 1, value + 'b');
}

int main() {
    // init
    map<double, char> m;
    prevent_opt(&m);
    m = A(m, 14.14, 'c');
    prevent_opt(&m);
    return 0;
}

