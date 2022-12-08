#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(char val) {
    std::cout << val << std::endl;
}


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

map<char, char> ins(map<char, char> num, const char key, const char value) {
	sink(num.at(key));
    return num;
}

map<char, char> D(map<char, char> num, const char key, char value) {
    return ins(num, key / 2, value / 'b');
}

map<char, char> C(map<char, char> num, const char key, char value) {
    return D(num, key + 2, value + 'b');
}

map<char, char> B(map<char, char> num, const char key, char value) {
    return C(num, key * 2, value * 'b');
}

map<char, char> A(map<char, char> num, const char key, char value) {
    return B(num, key + 1, value + 'b');
}

int main() {
    map<char, char> m;
    prevent_opt(&m);
    m = A(m, 'a', 'c');
    prevent_opt(&m);
    return 0;
}

