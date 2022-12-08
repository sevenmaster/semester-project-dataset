#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, char>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 'b'));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<char, char>* num, const char key, const char value) {
    (*num).erase(key);
}

void D(map<char, char>* num, const char key, char value) {
    ins(num, key / 2, value / 'b');
}

void C(map<char, char>* num, const char key, char value) {
    D(num, key + 2, value + 'b');
}

void B(map<char, char>* num, const char key, char value) {
    C(num, key * 2, value * 'b');
}

void A(map<char, char>* num, const char key, char value) {
    B(num, key + 1, value + 'b');
}

int main() {
    map<char, char> m;
    prevent_opt(&m);
    A(&m, 'a', 'c');
    prevent_opt(&m);
    return 0;
}

