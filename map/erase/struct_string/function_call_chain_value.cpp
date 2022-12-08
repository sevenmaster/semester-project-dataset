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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<xy, string> ins(map<xy, string> num, const xy key, const string value) {
    num.erase(key);
    return num;
}

map<xy, string> D(map<xy, string> num, xy key, string value) {
    key.x = key.x  / 2;
    key.y = key.y  / 2;
    return ins(num, key, value + "D");
}

map<xy, string> C(map<xy, string> num, xy key, string value) {

    key.x = key.x  / 2;
    key.y = key.y  / 2;

    return D(num, key, value + "C");
}

map<xy, string> B(map<xy, string> num, xy key, string value) {

    key.x = key.x  / 2;
    key.y = key.y  / 2;
    return C(num, key, value + "B");

}

map<xy, string> A(map<xy, string> num, xy key, string value) {

    key.x = key.x  / 2;
    key.y = key.y  / 2;
    return B(num, key, value + "A");
}

int main() {
    xy t = {1, 2};
    map<xy, string> m;
    prevent_opt(&m);
    m = A(m, t, "Hi");
    prevent_opt(&m);
    return 0;
}

