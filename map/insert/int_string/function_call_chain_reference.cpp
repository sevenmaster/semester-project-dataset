#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, string>* num) {
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

void ins(map<int, string>* num, const int key, const string value) {
    (*num)[key] = value;
}

void D(map<int, string>* num, const int key, string value) {
    ins(num, key / 2, value + "A");
}

void C(map<int, string>* num, const int key, string value) {
    D(num, key + 2, value + "A");
}

void B(map<int, string>* num, const int key, string value) {
    C(num, key * 2, value + "A");
}

void A(map<int, string>* num, const int key, string value) {
    B(num, key + 1, value + "A");
}

int main() {
    // init
    map<int, string> m;
    prevent_opt(&m);
    A(&m, 2, "Hi");
    prevent_opt(&m);
    return 0;
}

