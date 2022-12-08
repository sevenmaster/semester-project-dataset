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

vector<char> ins(vector<char> num, int pos) {
    sink(num.at(pos));
    return num;
}

vector<char> D(vector<char> num, int pos) {
    return ins(num, pos - 5);
}

vector<char> C(vector<char> num, int pos) {
    return D(num, pos * 2);
}

vector<char> B(vector<char> num, int pos) {
    return C(num, pos + 1);
}

vector<char> A(vector<char> num, int pos) {
    return B(num, pos / 2);
}

int main() {
    int pos = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    num = A(num, pos);
    prevent_opt(&num);
    return 0;
}

