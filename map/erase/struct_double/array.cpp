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

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 13.37));
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    xy t = {1, 2};
    int it = nolibrand();
    map<xy, char> m[it];
    prevent_opt(&m[it / 2]);
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        m->insert(make_pair(t, j / 13.37));
    }
    prevent_opt(&m[it / 2]);
    return 0;
}

