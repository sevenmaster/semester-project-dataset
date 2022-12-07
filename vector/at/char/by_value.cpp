#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

vector<char> ins(vector<char> num) {
    num.at(1);
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<char>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(i);
    }
    //print a random element into num
    char a = num->at(rand());
    printf("%c", a);
}

int main() {
    vector<char> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

