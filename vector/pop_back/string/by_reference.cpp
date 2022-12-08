#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    string a = num->at(rand());
    printf("%s", a.c_str());
}

void pop(vector<string>* num) {
    num->pop_back();
}

int main() {
    vector<string> num;
    prevent_opt(&num);
    pop(&num);
    prevent_opt(&num);
    return 0;
}
