#include <iostream>
#include <map>
#include <string>

void __attribute__ ((noinline)) sink(std::string val) {
    std::cout << val << std::endl;
}


using namespace std;

struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};
void __attribute__ ((noinline)) prevent_opt(map<xy, string>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, to_string(j)));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}


void ins(map<xy, string>* num, const xy key, const string value) {
	sink((*num).at(key));
}

void D(map<xy, string>* num, xy key, string value) {
    key.x = key.x  / 2;
    key.y = key.y  / 2;
    ins(num, key, value + "D");
}

void C(map<xy, string>* num, xy key, string value) {
    key.x = key.x + 2;
    key.y = key.y + 2;
    D(num, key, value + "C");
}

void B(map<xy, string>* num, xy key, string value) {
    key.x = key.x * 2;
    key.y = key.y * 2;
    C(num, key, value + "B");
}

void A(map<xy, string>* num, xy key, string value) {
    key.x = key.x + 1;
    key.y = key.y + 1;
    B(num, key, value + "A");
}

int main() {
    xy t = {1, 2};
    map<xy, string> m;
    prevent_opt(&m);
    A(&m, t, "Hi");
    prevent_opt(&m);
    return 0;
}

