#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, char>* num) {
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

void ins(map<double, char>* num) {
    (*num).erase(14.14);
}

int main() {
    map<double, char> m;
    prevent_opt(&m);
    ins(&m);
    prevent_opt(&m);
    return 0;
}

