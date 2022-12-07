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

void ins(set<xy>* num, xy val) {
    num->erase(val);
}

void D(set<xy>* num, xy val) {
    val.x = val.x / 2;
    val.y = val.y / 2;
    ins(num, val);
}

void C(set<xy>* num, xy val) {
    val.x = val.x - 5;
    val.y = val.y - 5;
    D(num, val);
}

void B(set<xy>* num, xy val) {
    val.x = val.x * 4;
    val.y = val.y * 4;
    C(num, val);
}

void A(set<xy>* num, xy val) {
    val.x = val.x + 1;
    val.y = val.y + 1;
    B(num, val);
}

int main() {
    xy val = {nolibrand(), nolibrand()};
    set<xy> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}

