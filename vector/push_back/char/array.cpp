#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    // insert a random number of elements into num
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

int main() {
    int it = nolibrand() % 8;
    vector<char> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        num[i].push_back('A' + i);
    }
    prevent_opt(&num[it/2]);
    return 0;
}

