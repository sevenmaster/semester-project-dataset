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

void ins(map<string, double>* num, const string key, const double value) {
	sink((*num).at(key));
}

void D(map<string, double>* num, const string key, double value) {
    ins(num, key + "A", value / 2.2);
}

void C(map<string, double>* num, const string key, double value) {
    D(num, key + "a", value + 2.2);
}

void B(map<string, double>* num, const string key, double value) {
    C(num, key + "r", value * 3.2);
}

void A(map<string, double>* num, const string key, double value) {
    B(num, key + "A", value + 1.2);
}

int main() {
    map<string, double> m;
    prevent_opt(&m);
    A(&m, "Hello World", 13.37);
    prevent_opt(&m);
    return 0;
}

