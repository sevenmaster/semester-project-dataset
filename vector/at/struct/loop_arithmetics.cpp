#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


struct xy {
    int x;
    int y;
};

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    // insert a random number elements into num
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i};
        num->push_back(t);
    }
    //print a random element into num
    xy a = num->at(rand());
    printf("%d,%d", a.x, a.y);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(xy val) {
    printf("%d,%d", val.x, val.y);
}

int main() {
    int it = nolibrand();
    vector<xy> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        int a = i + it - it / 2 - 2;
        sink(num.at(a));
    }
    prevent_opt(&num);
    return 0;
}

