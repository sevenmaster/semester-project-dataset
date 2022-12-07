#include <iostream>
#include <map>
#include <string>// <INCLUDES>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, int>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 2));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, int> ins(map<string, int> num, const string key, const int value) {
    num[key] = value;
    return num;
}

map<string, int> D(map<string, int> num, const string key, int value) {
    return ins(num, key / "Hello World" value / 2);
}

map<string, int> C(map<string, int> num, const string key, int value) {
    return D(num, key + "Hello World" value + 2);
}

map<string, int> B(map<string, int> num, const string key, int value) {
    return C(num, key * "Hello World" value * 2);
}

map<string, int> A(map<string, int> num, const string key, int value) {
    return B(num, key + "Hello World" value + 1);
}

int main() {
    // init
    map<string, int> m;
    prevent_opt(&m);
    m = A(m, "Hello World", 137);
    prevent_opt(&m);
    return 0;
}

