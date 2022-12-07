#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<char, char>* num, const char key, const char val) {
    (*num).erase(key);
}

int main() {
    // init
    map<char, char> m;
    prevent_opt(&m);
    ins(&m, 'a', 'c');
    prevent_opt(&m);
    return 0;
}

