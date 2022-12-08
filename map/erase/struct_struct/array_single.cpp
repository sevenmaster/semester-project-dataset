#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, t));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    xy t = {1, 2};
    int it = nolibrand();
    map<xy, xy> m[it];
    prevent_opt(&m[it / 2]);
    m[it / 2].erase(t);
    prevent_opt(&m[it / 2]);
    return 0;
}

