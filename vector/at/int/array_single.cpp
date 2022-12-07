#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<int>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
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
    prevent_opt(&num[it / 2]);
    int val = num[it / 2].at(it / 2 + 1);
    sink(val);
    prevent_opt(&num[it / 2]);
    return 0;
}

