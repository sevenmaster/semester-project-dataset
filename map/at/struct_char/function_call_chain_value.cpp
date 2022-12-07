#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

void __attribute__ ((noinline)) sink(char val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 'b'));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<xy, char> ins(map<xy, char> num, const xy key, const char value) {
	sink(num.at(key));
    return num;
}

map<xy, char> D(map<xy, char> num, const xy key, char value) {
    xy t = {key.x / 2, key.y / 2};
    return ins(num, t, value / 'b');
}

map<xy, char> C(map<xy, char> num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    return D(num, t, value + 'b');
}

map<xy, char> B(map<xy, char> num, const xy key, char value) {
    xy t = {key.x * 2, key.y * 2};
    return C(num, t, value * 'b');
}

map<xy, char> A(map<xy, char> num, const xy key, char value) {
    xy t = {key.x + 2, key.y + 2};
    return B(num, t, value + 'b');
}

int main() {
    xy t = {1, 2};
    map<xy, char> m;
    prevent_opt(&m);
    m = A(m, t, 'c');
    prevent_opt(&m);
    return 0;
}

