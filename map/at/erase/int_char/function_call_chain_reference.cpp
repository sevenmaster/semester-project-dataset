#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, char>* num) {
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

void ins(map<int, char>* num, const int key, const int value) {
	sink((*num).at(key));
}

void D(map<int, char>* num, const int key, int value) {
    ins(num, key / 2, value / 'b');
}

void C(map<int, char>* num, const int key, int value) {
    D(num, key + 2, value + 'b');
}

void B(map<int, char>* num, const int key, int value) {
    C(num, key * 2, value * 'b');
}

void A(map<int, char>* num, const int key, int value) {
    B(num, key + 1, value + 'b');
}

int main() {
    // init
    map<int, char> m;
    prevent_opt(&m);
    A(&m, 2, 'b');
    prevent_opt(&m);
    return 0;
}

