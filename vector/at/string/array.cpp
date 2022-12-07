#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    printf("%s", a.c_str());
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(string val) {
    printf("%s", val.c_str());
}

int main() {
    int it = nolibrand();
    vector<string> num[it];
    prevent_opt(&num[it/2]);
    for (int i = 0; i < it; i++) {
        sink(num[i].at(i));
    }
    prevent_opt(&num[it/2]);
    return 0;
}

