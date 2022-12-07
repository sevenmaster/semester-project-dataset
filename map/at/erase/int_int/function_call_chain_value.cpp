#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, int>* num) {
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

map<int, int> ins(map<int, int> num, const int key, const int value) {
	sink(num.at(key));
    return num;
}

map<int, int> D(map<int, int> num, const int key, int value) {
    return ins(num, key / 2, value / 2);
}

map<int, int> C(map<int, int> num, const int key, int value) {
    return D(num, key + 2, value + 2);
}

map<int, int> B(map<int, int> num, const int key, int value) {
    return C(num, key * 2, value * 2);
}

map<int, int> A(map<int, int> num, const int key, int value) {
    return B(num, key + 1, value + 1);
}

int main() {
    // init
    map<int, int> m;
    prevent_opt(&m);
    m = A(m, 2, 137);
    prevent_opt(&m);
    return 0;
}

