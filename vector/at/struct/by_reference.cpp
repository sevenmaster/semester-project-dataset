#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


struct xy {
    int x;
    int y;
};

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i};
        num->push_back(t);
    }
    //print a random element into num
    xy a = num->at(rand());
    printf("%d,%d", a.x, a.y);
}

void __attribute__ ((noinline)) sink(xy val) {
    printf("%d,%d", val.x, val.y);
}

void ins(vector<xy>* num) {
    xy val = num->at(1);
    sink(val);
}

int main() {
    vector<xy> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

