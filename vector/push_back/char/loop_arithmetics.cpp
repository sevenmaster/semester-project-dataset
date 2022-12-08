#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

int main() {
    int it = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        char a = i + it - it / 2 - 2;
        num.push_back(a);
    }
    prevent_opt(&num);
    return 0;
}
