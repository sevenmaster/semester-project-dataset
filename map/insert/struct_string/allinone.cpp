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

void __attribute__ ((noinline)) prevent_opt(map<xy, string>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}


int main() {
    xy t = {1, 2};
    map<xy, string> m;
    prevent_opt(&m);
    m[t] = "Hi";
    prevent_opt(&m);
    return 0;
}

