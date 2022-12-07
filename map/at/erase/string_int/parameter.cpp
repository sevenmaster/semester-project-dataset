#include <iostream>
#include <map>
#include <string>
void __attribute__ ((noinline)) sink(auto val) {
    std::cout << val << std::endl;
}



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

void ins(map<string, int>* num, const string key, const int val) {
	sink((*num).at(key));
}

int main() {
    // init
    map<string, int> m;
    prevent_opt(&m);
    ins(&m, "Hello World", 137);
    prevent_opt(&m);
    return 0;
}

