#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(std::string val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<char, string>* num, const char key, const string val) {
	sink((*num).at(key));
}

int main() {
    map<char, string> m;
    prevent_opt(&m);
    ins(&m, 'a', "Hi");
    prevent_opt(&m);
    return 0;
}

