#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 'b'));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void ins(map<xy, char>* num, const xy key, const char value) {
    (*num).erase(key);
}

void D(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x / 2, key.y / 2};
    ins(num, t, value / 'b');
}

void C(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    D(num, t, value + 'b');
}

void B(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    C(num, t, value * 'b');
}

void A(map<xy, char>* num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    B(num, t, value + 'b');
}

int main() {
    xy t = {1, 2};
    map<xy, char> m;
    prevent_opt(&m);
    A(&m, t, 'c');
    prevent_opt(&m);
    return 0;
}

