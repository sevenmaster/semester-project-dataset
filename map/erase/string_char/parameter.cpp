#include <iostream>
#include <map>
#include <string>// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<string, char>* num, const string key, const char val) {
    (*num).erase(key);
}

int main() {
    // init
    map<string, char> m;
    prevent_opt(&m);
    ins(&m, "Hello World", 'c');
    prevent_opt(&m);
    return 0;
}

