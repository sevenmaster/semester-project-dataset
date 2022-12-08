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

int main() {
    int it = nolibrand();
    map<double, int> m[it];
    prevent_opt(&m[it / 2]);
	sink(m[it / 2].at(14.14));
    prevent_opt(&m[it / 2]);
    return 0;
}

