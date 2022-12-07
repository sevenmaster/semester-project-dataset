#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, string>* num) {
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

void ins(map<char, string>* num, const char key, const string value) {
    (*num).erase(key);
}

void D(map<char, string>* num, const char key, string value) {
    ins(num, key / 2, value + "A");
}

void C(map<char, string>* num, const char key, string value) {
    D(num, key + 2, value + "A");
}

void B(map<char, string>* num, const char key, string value) {
    C(num, key * 2, value + "A");
}

void A(map<char, string>* num, const char key, string value) {
    B(num, key + 1, value + "A");
}

int main() {
    // init
    map<char, string> m;
    prevent_opt(&m);
    A(&m, 'a', "Hi");
    prevent_opt(&m);
    return 0;
}

