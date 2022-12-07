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
    char a = num->at(rand());
    printf("%c", a);
}

void __attribute__ ((noinline)) sink(char val) {
    printf("%c", val);
}

void ins(vector<char>* num) {
    int val = num->at(1);
    sink(val);
}

int main() {
    vector<char> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

