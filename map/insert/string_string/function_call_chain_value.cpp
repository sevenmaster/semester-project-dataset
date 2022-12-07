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

map<string, string> ins(map<string, string> num, const string key, const string value) {
    num[key] = value;
    return num;
}

map<string, string> D(map<string, string> num, const string key, string value) {
    return ins(num, key / "Hello World" value / 2.2);
}

map<string, string> C(map<string, string> num, const string key, string value) {
    return D(num, key + "Hello World" value + 2.2);
}

map<string, string> B(map<string, string> num, const string key, string value) {
    return C(num, key * "Hello World" value * 2.2);
}

map<string, string> A(map<string, string> num, const string key, string value) {
    return B(num, key + "Hello World" value + 1.2);
}

int main() {
    // init
    map<string, string> m;
    prevent_opt(&m);
    m = A(m, "Hello World", "Hi");
    prevent_opt(&m);
    return 0;
}
