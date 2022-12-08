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

void ins(vector<xy>* num, xy* val) {
    num->push_back(*val);
}

void D(vector<xy>* num, xy* val) {
    val->x = val->x - 5;
    val->y = val->y - 5;
    ins(num, val);
}

void C(vector<xy>* num, xy* val) {
    val->x = val->x * 2;
    val->y = val->y * 2;
    D(num, val);
}

void B(vector<xy>* num, xy* val) {
    val->x = val->x + 1;
    val->y = val->y + 1;
    C(num, val);
}

void A(vector<xy>* num, xy* val) {
    val->x = val->x / 2;
    val->y = val->y / 2;
    B(num, val);
}

int main() {
    int a = nolibrand();
    xy val = {a, a + 1};
    vector<xy> num;
    prevent_opt(&num);
    A(&num, &val);
    prevent_opt(&num);
    return 0;
}


