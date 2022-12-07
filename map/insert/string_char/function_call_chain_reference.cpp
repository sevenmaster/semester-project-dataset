#include <iostream>
#include <map>
#include <string>// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<string, char>* num, const string key, const char value) {
    (*num)[key] = value;
}

void D(map<string, char>* num, const string key, char value) {
    ins(num, key / "Hello World" value / 'b');
}

void C(map<string, char>* num, const string key, char value) {
    D(num, key + "Hello World" value + 'b');
}

void B(map<string, char>* num, const string key, char value) {
    C(num, key * "Hello World" value * 'b');
}

void A(map<string, char>* num, const string key, char value) {
    B(num, key + "Hello World" value + 'b');
}

int main() {
    // init
    map<string, char> m;
    prevent_opt(&m);
    A(&m, "Hello World", 'c');
    prevent_opt(&m);
    return 0;
}

