#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

void pop(vector<char>* num) {
    num->pop_back();
}

int main() {
    vector<char> num;
    prevent_opt(&num);
    pop(&num);
    prevent_opt(&num);
    return 0;
}
