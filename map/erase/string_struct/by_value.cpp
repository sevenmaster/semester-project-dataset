#include <iostream>
#include <map>
#include <string>


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
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<string, xy> ins(map<string, xy> num) {
    xy t = {1, 2};
    num.erase("Hello World");
    return num;
}

int main() {
    map<string, xy> m;
    prevent_opt(&m);
    m = ins(m);
    prevent_opt(&m);
    return 0;
}

