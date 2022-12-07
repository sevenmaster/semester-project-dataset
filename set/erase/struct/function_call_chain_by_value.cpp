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

set<xy> ins(set<xy> num, xy val) {
    num.erase(val);
    return num;
}

set<xy> D(set<xy> num, xy val) {
    val.x = val.x / 2;
    val.y = val.x / 2;
    return ins(num, val);
}

set<xy> C(set<xy> num, xy val) {
    val.x = val.x + 2;
    val.y = val.y + 2;
    return D(num, val);
}

set<xy> B(set<xy> num, xy val) {
    val.x = val.x * 4;
    val.y = val.y * 4;
    return C(num, val);
}

set<xy> A(set<xy> num, xy val) {
    val.x = val.x * 4;
    val.y = val.y * 4;
    return B(num, val);
}

int main() {
    xy val = {nolibrand(), nolibrand()};
    set<xy> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}

