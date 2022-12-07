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

void ins(map<char, int>* num, const char key, const int val) {
    (*num).erase(key);
}

int main() {
    // init
    map<char, int> m;
    prevent_opt(&m);
    ins(&m, 'a', 137);
    prevent_opt(&m);
    return 0;
}

