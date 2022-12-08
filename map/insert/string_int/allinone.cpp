#include <iostream>
#include <map>
#include <string>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, int>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), j / 2));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}


int main() {
    map<string, int> m;
    prevent_opt(&m);
    m["Hello World"] = 137;
    prevent_opt(&m);
    return 0;
}

