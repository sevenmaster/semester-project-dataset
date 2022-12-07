#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<double, string>* num, const double key, const string value) {
	sink((*num).at(key));
}

void D(map<double, string>* num, const double key, string value) {
    ins(num, key / 2, value + "A");
}

void C(map<double, string>* num, const double key, string value) {
    D(num, key + 2, value + "A");
}

void B(map<double, string>* num, const double key, string value) {
    C(num, key * 2, value + "A");
}

void A(map<double, string>* num, const double key, string value) {
    B(num, key + 1, value + "A");
}

int main() {
    // init
    map<double, string> m;
    prevent_opt(&m);
    A(&m, 14.14, "Hi");
    prevent_opt(&m);
    return 0;
}

