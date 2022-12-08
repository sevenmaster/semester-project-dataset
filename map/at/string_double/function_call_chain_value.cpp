#include <iostream>
#include <map>
#include <string>
void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, double>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), j / 2.0));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, double> ins(map<string, double> num, const string key, const double value) {
	sink(num.at(key));
    return num;
}

map<string, double> D(map<string, double> num, const string key, double value) {
    return ins(num, key + "9", value / 2.2);
}

map<string, double> C(map<string, double> num, const string key, double value) {
    return D(num, key + "a", value + 2.2);
}

map<string, double> B(map<string, double> num, const string key, double value) {
    return C(num, key + "k", value * 2.2);
}

map<string, double> A(map<string, double> num, const string key, double value) {
    return B(num, key + "A", value + 1.2);
}

int main() {
    map<string, double> m;
    prevent_opt(&m);
    m = A(m, "Hello World", 13.37);
    prevent_opt(&m);
    return 0;
}

