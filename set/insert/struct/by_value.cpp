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
        num->insert(t);
    }
    for (xy c : *num) {
        printf("%d, %d", c.x, c.y);
    }
}


set<xy> ins(set<xy> num) {
    xy t = {1, 2};
    num.insert(t);
    return num;
}

int main() {
    set<xy> num;
    prevent_opt(&num);
    ins(num);
    prevent_opt(&num);
    return 0;
}
