#include <iostream>
#include <map>
#include <string>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<string, string>* num, const string key, const string value) {
    (*num)[key] = value;
}

void D(map<string, string>* num, const string key, string value) {
    ins(num, key / "Hello World" value / 2.2);
}

void C(map<string, string>* num, const string key, string value) {
    D(num, key + "Hello World" value + 2.2);
}

void B(map<string, string>* num, const string key, string value) {
    C(num, key * "Hello World" value * 2.2);
}

void A(map<string, string>* num, const string key, string value) {
    B(num, key + "Hello World" value + 1.2);
}

int main() {
    // init
    map<string, string> m;
    prevent_opt(&m);
    A(&m, "Hello World", "Hi");
    prevent_opt(&m);
    return 0;
}

