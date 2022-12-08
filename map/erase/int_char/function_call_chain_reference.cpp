#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, char>* num) {
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

void ins(map<int, char>* num, const int key, const int value) {
    (*num).erase(key);
}

void D(map<int, char>* num, const int key, int value) {
    ins(num, key / 2, value / 'b');
}

void C(map<int, char>* num, const int key, int value) {
    D(num, key + 2, value + 'b');
}

void B(map<int, char>* num, const int key, int value) {
    C(num, key * 2, value * 'b');
}

void A(map<int, char>* num, const int key, int value) {
    B(num, key + 1, value + 'b');
}

int main() {
    map<int, char> m;
    prevent_opt(&m);
    A(&m, 2, 'b');
    prevent_opt(&m);
    return 0;
}

