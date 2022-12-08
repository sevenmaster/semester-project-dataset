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

void ins(vector<xy>* num) {
    xy t = {1, 2};
    num->push_back(t);
}

int main() {
    vector<xy> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

