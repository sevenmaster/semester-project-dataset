#include <iostream>
#include <map>
// <INCLUDES>

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

map<int, char> ins(map<int, char> num, const int key, const int value) {
    num.erase(key);
    return num;
}

map<int, char> D(map<int, char> num, const int key, int value) {
    return ins(num, key / 2, value / 'b');
}

map<int, char> C(map<int, char> num, const int key, int value) {
    return D(num, key + 2, value + 'b');
}

map<int, char> B(map<int, char> num, const int key, int value) {
    return C(num, key * 2, value * 'b');
}

map<int, char> A(map<int, char> num, const int key, int value) {
    return B(num, key + 1, value + 'b');
}

int main() {
    // init
    map<int, char> m;
    prevent_opt(&m);
    m = A(m, 2, 'b');
    prevent_opt(&m);
    return 0;
}

