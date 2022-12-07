#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(char val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, char>* num) {
    for (int j = 0; j < rand(); j++) {
        // opt init
        num->insert(make_pair(j, j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<int, char> ins(map<int, char> num) {
	sink(num.at(2));
    return num;
}

int main() {
    // init
    map<int, char> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}

