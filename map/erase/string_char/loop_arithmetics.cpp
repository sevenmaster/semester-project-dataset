#include <iostream>
#include <map>
#include <string>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, char>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), j / 'b'));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    map<string, char> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
        m.erase(to_string(j) + "hi");
    }
    prevent_opt(&m);
    return 0;
}

