#include <iostream>
#include <map>
// <INCLUDES>

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

void ins(map<char, int>* num, const char key, const int value) {
    (*num).erase(key);
}

void D(map<char, int>* num, const char key, int value) {
    ins(num, key / 2, value / 2);
}

void C(map<char, int>* num, const char key, int value) {
    D(num, key + 2, value + 2);
}

void B(map<char, int>* num, const char key, int value) {
    C(num, key * 2, value * 2);
}

void A(map<char, int>* num, const char key, int value) {
    B(num, key + 1, value + 1);
}

int main() {
    // init
    map<char, int> m;
    prevent_opt(&m);
    A(&m, 'a', 137);
    prevent_opt(&m);
    return 0;
}

