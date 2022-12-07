#include <stdlib.h>
#include <cstdio>
#include <set>
#include <iostream>
using namespace std;

struct xy {
    int x;
    int y;
};

bool operator<(const xy& lhs, const xy& rhs) {
  if (lhs.x != rhs.x) {
    return lhs.x < rhs.x;
  } else {
    return lhs.y < rhs.y;
  }
}

void __attribute__ ((noinline)) prevent_opt(set <xy>* num) {
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i+1};
        num->erase(t);
    }
    for (xy c : *num) {
        printf("%d, %d", c.x, c.y);
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    set<xy> num[it];
    prevent_opt(&num[it / 2]);
    xy t = {1, 2};
    num[it / 2].erase(t);
    prevent_opt(&num[it / 2]);
    return 0;
}
