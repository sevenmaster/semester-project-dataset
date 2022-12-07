#include <iostream>
#include <map>
// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<int, string>* num, const int key, const string val) {
    (*num)[key] = val;
}

int main() {
    // init
    map<int, string> m;
    prevent_opt(&m);
    ins(&m, 2, "Hi");
    prevent_opt(&m);
    return 0;
}

