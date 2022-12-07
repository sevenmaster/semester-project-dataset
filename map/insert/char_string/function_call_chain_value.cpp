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

map<char, string> ins(map<char, string> num, const char key, const string value) {
    num[key] = value;
    return num;
}

map<char, string> D(map<char, string> num, const char key, string value) {
    return ins(num, key / 2, value + "A");
}

map<char, string> C(map<char, string> num, const char key, string value) {
    return D(num, key + 2, value + "A");
}

map<char, string> B(map<char, string> num, const char key, string value) {
    return C(num, key * 2, value + "A");
}

map<char, string> A(map<char, string> num, const char key, string value) {
    return B(num, key + 1, value + "A");
}

int main() {
    // init
    map<char, string> m;
    prevent_opt(&m);
    m = A(m, 'a', "Hi");
    prevent_opt(&m);
    return 0;
}

