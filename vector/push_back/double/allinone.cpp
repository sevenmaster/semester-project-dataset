#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<double>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
    int a = num->at(rand());
    printf("%d", a);
}

int main() {
    vector<double> num;
    prevent_opt(&num);
    num.push_back(13.37);
    prevent_opt(&num);
    return 0;
}

