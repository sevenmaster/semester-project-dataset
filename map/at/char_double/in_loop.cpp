#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, double>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 2.0));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    // init
    map<char, double> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
	sink(m.at(j));
    }
    prevent_opt(&m);
    return 0;
}

