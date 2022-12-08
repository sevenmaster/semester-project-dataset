#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

void __attribute__ ((noinline)) sink(xy val) {
    std::cout << val.x << val.y << std::endl;
}


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

map<xy, xy> ins(map<xy, xy> num, const xy key, const xy value) {
	sink(num.at(key));
    return num;
}

map<xy, xy> D(map<xy, xy> num, const xy key, xy value) {
    xy t = {key.x / 2, key.y / 2};
    return ins(num, t, t);
}

map<xy, xy> C(map<xy, xy> num, const xy key, xy value) {
    xy t = {key.x + 2, key.y + 2};
    return D(num, t, t);
}

map<xy, xy> B(map<xy, xy> num, const xy key, xy value) {
    xy t = {key.x * 2, key.y * 2};
    return C(num, t, t);
}

map<xy, xy> A(map<xy, xy> num, const xy key, xy value) {
    xy t = {key.x + 2, key.y + 2};
    return B(num, t, t);
}

int main() {
    xy t = {1, 2};
    map<xy, xy> m;
    prevent_opt(&m);
    m = A(m, t, t);
    prevent_opt(&m);
    return 0;
}

