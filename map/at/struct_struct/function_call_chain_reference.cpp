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

void ins(map<xy, xy>* num, const xy key, const xy value) {
	sink((*num).at(key));
}

void D(map<xy, xy>* num, const xy key, xy value) {
    xy t = {key.x / 2, key.y / 2};
    ins(num, t, t);
}

void C(map<xy, xy>* num, const xy key, xy value) {
    xy t = {key.x + 2, key.y + 2};
    D(num, t, t);
}

void B(map<xy, xy>* num, const xy key, xy value) {
    xy t = {key.x + 2, key.y + 2};
    C(num, t, t);
}

void A(map<xy, xy>* num, const xy key, xy value) {
    xy t = {key.x + 2, key.y + 2};
    B(num, t, t);
}

int main() {
    xy t = {1, 2};
    map<xy, xy> m;
    prevent_opt(&m);
    A(&m, t, t);
    prevent_opt(&m);
    return 0;
}

