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

void __attribute__ ((noinline)) prevent_opt(map<int, xy>* num) {
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

map<int, xy> ins(map<int, xy> num, const int key, const xy value) {
    num.erase(key);
    return num;
}

map<int, xy> D(map<int, xy> num, const int key, xy value) {
    value.x = value.x / 2;
    value.y = value.y / 2;
    return ins(num, key / 2, value);
}

map<int, xy> C(map<int, xy> num, const int key, xy value) {
    value.x = value.x + 2;
    value.y = value.y + 2;
    return D(num, key + 2, value);
}

map<int, xy> B(map<int, xy> num, const int key, xy value) {
    value.x = value.x * 2;
    value.y = value.y * 2;
    return C(num, key * 2, value);
}

map<int, xy> A(map<int, xy> num, const int key, xy value) {
    value.x = value.x + 1;
    value.y = value.y + 1;
    return B(num, key + 1, value);
}

int main() {
    xy t = {1, 2};
    map<int, xy> m;
    prevent_opt(&m);
    m = A(m, 2, t);
    prevent_opt(&m);
    return 0;
}

