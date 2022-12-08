#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    string a = num->at(rand());
    printf("%s", a.c_str());
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

string __attribute__ ((noinline)) randStr() {
    return to_string(rand());
}

int main() {
    int it = nolibrand();
    vector<string> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        num[i].push_back(randStr());
    }
    prevent_opt(&num[it/2]);
    return 0;
}

