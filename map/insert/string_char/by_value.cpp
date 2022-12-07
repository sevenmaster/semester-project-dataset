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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, char> ins(map<string, char> num) {
    num["Hello World"] = 'c';
    return num;
}

int main() {
    // init
    map<string, char> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}
