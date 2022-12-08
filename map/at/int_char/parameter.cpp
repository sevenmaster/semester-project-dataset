#include <iostream>
#include <map>

void __attribute__ ((noinline)) sink(char val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<int, char>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, j / 'b'));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

void ins(map<int, char>* num, const int key, const int val) {
	sink((*num).at(key));
}

int main() {
    map<int, char> m;
    prevent_opt(&m);
    ins(&m, 2, 'b');
    prevent_opt(&m);
    return 0;
}

