#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<int>* num, int val) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
    int a = num->at(rand());
    printf("%d,%d", a, val);
}

int main() {
    vector<int> num;
    int val = 0;
    prevent_opt(&num, val);
    val = num.at(1);
    prevent_opt(&num, val);
    return 0;
}

