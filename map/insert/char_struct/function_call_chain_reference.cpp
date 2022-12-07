#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

// <INCLUDES>

using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<char, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(j, t));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<char, xy>* num, const char key, const xy value) {
    (*num)[key] = value;
}

void D(map<char, xy>* num, const char key, xy value) {
    value.x = value.x / 2;
    value.y = value.y / 2;
    ins(num, key / 2, value);
}

void C(map<char, xy>* num, const char key, xy value) {
    value.x = value.x + 2;
    value.y = value.y + 2;
    D(num, key + 2, value);
}

void B(map<char, xy>* num, const char key, xy value) {
    value.x = value.x * 2;
    value.y = value.y * 2;
    C(num, key * 2, value);
}

void A(map<char, xy>* num, const char key, xy value) {
    value.x = value.x + 1;
    value.y = value.y + 1;
    B(num, key + 1, value);
}

int main() {
    xy t = {1, 2};
    map<char, xy> m;
    prevent_opt(&m);
    A(&m, 'a', t);
    prevent_opt(&m);
    return 0;
}

