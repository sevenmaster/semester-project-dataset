#include <iostream>
#include <map>
#include <string>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(to_string(j), to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<string, string>* num, const string key, const string val) {
    (*num).erase(key);
}

int main() {
    map<string, string> m;
    prevent_opt(&m);
    ins(&m, "Hello World", "Hi");
    prevent_opt(&m);
    return 0;
}

