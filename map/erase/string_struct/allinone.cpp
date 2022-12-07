#include <iostream>
#include <map>
#include <string>
// <INCLUDES>

struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

using namespace std;

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


int main() {
    xy t = {1, 2};
    map<string, xy> m;
    prevent_opt(&m);
    m.erase("Hello World");
    prevent_opt(&m);
    return 0;
}

