#include <iostream>
#include <map>
#include <string>

void __attribute__ ((noinline)) sink(std::string val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, string>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<string, string>* num, const string key, const string val) {
	sink((*num).at(key));
}

int main() {
    // init
    map<string, string> m;
    prevent_opt(&m);
    ins(&m, "Hello World", "Hi");
    prevent_opt(&m);
    return 0;
}

