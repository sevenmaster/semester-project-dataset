#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

struct xy {
    int x;
    int y;
};

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    // insert a random number of elements into num
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

void ins(vector<xy>* num, int val) {
    sink(num->at(val));
}

int main() {
    int val = nolibrand();
    vector<xy> num;
    prevent_opt(&num);
    ins(&num, val);
    prevent_opt(&num);
    return 0;
}

