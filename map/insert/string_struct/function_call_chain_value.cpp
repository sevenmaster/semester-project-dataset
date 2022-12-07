#include <iostream>
#include <map>
#include <string>
// <INCLUDES>

using namespace std;
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


void __attribute__ ((noinline)) prevent_opt(map<string, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(to_string(j), t));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, xy> ins(map<string, xy> num, const string key, const xy value) {
    num[key] = value;
    return num;
}

map<string, xy> D(map<string, xy> num, const string key, xy value) {
    value.x = value.x / 2;
    value.y = value.y / 2;
    return ins(num, key + "A", value);
}

map<string, xy> C(map<string, xy> num, const string key, xy value) {
    value.x = value.x + 2;
    value.y = value.y + 2;
    return D(num, key + "A", value);
}

map<string, xy> B(map<string, xy> num, const string key, xy value) {
    value.x = value.x * 2;
    value.y = value.y * 2;
    return C(num, key + "B", value);
}

map<string, xy> A(map<string, xy> num, const string key, xy value) {
    value.x = value.x + 1;
    value.y = value.y + 1;
    return B(num, key + "A", value);
}

int main() {
    xy t = {1, 2};
    map<string, xy> m;
    prevent_opt(&m);
    m = A(m, "Hello World", t);
    prevent_opt(&m);
    return 0;
}

