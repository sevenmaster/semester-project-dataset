#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<char, string>* num, const char key, const string value) {
    (*num)[key] = value;
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
    map<char, string> m;
    prevent_opt(&m);
    A(&m, 'a', "Hi");
    prevent_opt(&m);
    return 0;
}

