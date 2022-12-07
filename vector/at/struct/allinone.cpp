#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

struct xy {
    int x;
    int y;
};

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num, xy val) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i};
        num->push_back(t);
    }
    //print a random element into num
    xy a = num->at(rand());
    printf("%d,%d %d,%d", a.x, a.y, val.x, val.y);
}

int main() {
    vector<xy> num;
    xy val = {1, 2};
    prevent_opt(&num, val);
    val = num.at(1);
    prevent_opt(&num, val);
    return 0;
}

