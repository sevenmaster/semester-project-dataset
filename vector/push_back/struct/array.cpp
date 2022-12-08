#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

struct xy {
    int x;
    int y;
};


void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i+1};
        num->push_back(t);
    }
    xy a = num->at(rand());
    printf("%d,%d", a.x, a.y);
}



int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    vector<xy> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        xy t = {i, i+1};
        num[i].push_back(t);
    }
    prevent_opt(&num[it/2]);
    return 0;
}

