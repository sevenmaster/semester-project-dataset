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

void ins(vector<xy>* num, int pos) {
    sink(num->at(pos));
}

void D(vector<xy>* num, int pos) {
    ins(num, pos - 5);
}

void C(vector<xy>* num, int pos) {
    D(num, pos * 2);
}

void B(vector<xy>* num, int pos) {
    C(num, pos + 1);
}

void A(vector<xy>* num, int pos) {
    B(num, pos / 2);
}

int main() {
    int val = nolibrand();
    vector<xy> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}
