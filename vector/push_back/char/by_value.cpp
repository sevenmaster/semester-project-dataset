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
    int a = num->at(rand());
    printf("%d", a);
}


vector<char> ins(vector<char> num) {
    num.push_back('A');
    return num;
}

int main() {
    vector<char> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

