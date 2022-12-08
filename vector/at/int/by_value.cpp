#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> ins(vector<int> num) {
    num.at(1);
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<int>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

int main() {
    vector<int> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}


