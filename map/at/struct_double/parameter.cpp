#include <iostream>
#include <map>
struct xy {
    int x; int y;
    bool operator<(const xy& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

void __attribute__ ((noinline)) sink(double val) {
    std::cout << val << std::endl;
}


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<xy, char>* num) {
    for (int j = 0; j < rand(); j++) {
        xy t = {j, j+1};
        num->insert(make_pair(t, j / 13.37));
    }
    // print the contents of num
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first.x << it->first.y << " " << it->second << endl;
    }
}

void ins(map<xy, char>* num, const xy key, const char val) {
	sink((*num).at(key));
}

int main() {
    xy t = {1, 2};
    map<xy, char> m;
    prevent_opt(&m);
    ins(&m, t, 13.37);
    prevent_opt(&m);
    return 0;
}

