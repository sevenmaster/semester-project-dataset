#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(int val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, int>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 2));
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
    int it = nolibrand();
    map<char, int> m[it];
    prevent_opt(&m[it / 2]);
	sink(m[it / 2].at('a'));
    prevent_opt(&m[it / 2]);
    return 0;
}

