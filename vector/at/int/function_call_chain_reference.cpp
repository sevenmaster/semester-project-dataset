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

void ins(vector<int>* num, int pos) {
    sink(num->at(pos));
}

void D(vector<int>* num, int pos) {
    ins(num, pos - 5);
}

void C(vector<int>* num, int pos) {
    D(num, pos * 2);
}

void B(vector<int>* num, int pos) {
    C(num, pos + 1);
}

void A(vector<int>* num, int pos) {
    B(num, pos / 2);
}

int main() {
    int val = nolibrand();
    vector<int> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}
