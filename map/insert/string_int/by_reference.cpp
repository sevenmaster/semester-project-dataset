#include <iostream>
#include <map>
#include <string>// <INCLUDES>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, int>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 2));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<string, int>* num) {
    (*num)["Hello World"] = 137;
}

int main() {
    // init
    map<string, int> m;
    prevent_opt(&m);
    ins(&m);
    prevent_opt(&m);
    return 0;
}

