#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
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
    vector<char> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        sink(num[i].at(i));
    }
    prevent_opt(&num[it/2]);
    return 0;
}

