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

vector<int> ins(vector<int> num, int val) {
    num.push_back(val);
    return num;
}

vector<int> D(vector<int> num, int val) {
    return ins(num, val - 5);
}

vector<int> C(vector<int> num, int val) {
    return D(num, val * 2);
}

vector<int> B(vector<int> num, int val) {
    return C(num, val + 1);
}

vector<int> A(vector<int> num, int val) {
    return B(num, val / 2);
}

int main() {
    int val = nolibrand();
    vector<int> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}


