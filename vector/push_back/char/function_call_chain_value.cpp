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
    int a = num->at(rand());
    printf("%d", a);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

vector<char> ins(vector<char> num, char val) {
    num.push_back(val);
    return num;
}

vector<char> D(vector<char> num, char val) {
    return ins(num, val - 5);
}

vector<char> C(vector<char> num, int val) {
    return D(num, val * 2);
}

vector<char> B(vector<char> num, char val) {
    return C(num, val + 1);
}

vector<char> A(vector<char> num, char val) {
    return B(num, val / 2);
}

int main() {
    char val = nolibrand();
    vector<char> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}


