#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<int>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(int val) {
    printf("%d", val);
}

int main() {
    int it = nolibrand();
    vector<int> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        int val = num[i].at(i);
        sink(val);
    }
    prevent_opt(&num[it/2]);
    return 0;
}

