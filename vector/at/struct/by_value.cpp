#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


struct xy {
    int x;
    int y;
};

vector<xy> ins(vector<xy> num) {
    num.at(1);
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i};
        num->push_back(t);
    }
    xy a = num->at(rand());
    printf("%d,%d", a.x, a.y);
}

int main() {
    vector<xy> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

