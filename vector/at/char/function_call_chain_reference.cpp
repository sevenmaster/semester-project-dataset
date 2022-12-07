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
    char a = num->at(rand());
    printf("%c", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(char val) {
    printf("%c", val);
}

void ins(vector<char>* num, int pos) {
    sink(num->at(pos));
}

void D(vector<char>* num, int pos) {
    ins(num, pos - 5);
}

void C(vector<char>* num, int pos) {
    D(num, pos * 2);
}

void B(vector<char>* num, int pos) {
    C(num, pos + 1);
}

void A(vector<char>* num, int pos) {
    B(num, pos / 2);
}

int main() {
    int val = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}
