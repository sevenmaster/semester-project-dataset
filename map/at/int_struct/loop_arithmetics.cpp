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

void __attribute__ ((noinline)) prevent_opt(map<int, xy>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(j, t));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second.x << it->second.y << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    map<int, xy> m;
    prevent_opt(&m);
    for (int j = 0; j < rand(); j++) {
        xy a = {j, j+1};
	sink(m.at(j));
    }
    prevent_opt(&m);
    return 0;
}

