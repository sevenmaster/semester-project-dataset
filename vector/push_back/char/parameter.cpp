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

void ins(vector<char>* num, char val) {
    num->push_back(val);
}

int main() {
    int val = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    ins(&num, val);
    prevent_opt(&num);
    return 0;
}

