#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    int a = num->at(rand());
    printf("%d", a);
}

void ins(vector<double>* num) {
    num->push_back(13.37);
}

int main() {
    vector<double> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

