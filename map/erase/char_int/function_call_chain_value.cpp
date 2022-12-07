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

map<char, int> ins(map<char, int> num, const char key, const int value) {
    num.erase(key);
    return num;
}

map<char, int> D(map<char, int> num, const char key, int value) {
    return ins(num, key / 2, value / 2);
}

map<char, int> C(map<char, int> num, const char key, int value) {
    return D(num, key + 2, value + 2);
}

map<char, int> B(map<char, int> num, const char key, int value) {
    return C(num, key * 2, value * 2);
}

map<char, int> A(map<char, int> num, const char key, int value) {
    return B(num, key + 1, value + 1);
}

int main() {
    // init
    map<char, int> m;
    prevent_opt(&m);
    m = A(m, 'a', 137);
    prevent_opt(&m);
    return 0;
}

