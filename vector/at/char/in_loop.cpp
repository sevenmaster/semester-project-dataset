#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    char a = num->at(rand());
    printf("%c", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(char val) {
    printf("%c", val);
}

int main() {
    int it = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    for (int i = 0; i < it; i++) {
        sink(num.at(nolibrand()));
    }
    prevent_opt(&num);
    return 0;
}

