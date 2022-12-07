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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(xy val) {
    printf("%d,%d", val.x, val.y);
}

vector<xy> ins(vector<xy> num, int pos) {
    sink(num.at(pos));
    return num;
}

vector<xy> D(vector<xy> num, int pos) {
    return ins(num, pos - 5);
}

vector<xy> C(vector<xy> num, int pos) {
    return D(num, pos * 2);
}

vector<xy> B(vector<xy> num, int pos) {
    return C(num, pos + 1);
}

vector<xy> A(vector<xy> num, int pos) {
    return B(num, pos / 2);
}

int main() {
    int pos = nolibrand();
    vector<xy> num;
    prevent_opt(&num);
    num = A(num, pos);
    prevent_opt(&num);
    return 0;
}

