#include <iostream>
#include <map>
#include <string>
void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<string, double>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(to_string(j), j / 2.0));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<string, double>* num, const string key, const double val) {
	sink((*num).at(key));
}

int main() {
    // init
    map<string, double> m;
    prevent_opt(&m);
    ins(&m, "Hello World", 13.37);
    prevent_opt(&m);
    return 0;
}

