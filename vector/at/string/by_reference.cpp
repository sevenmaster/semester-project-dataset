#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    printf("%s", a.c_str());
}

void __attribute__ ((noinline)) sink(string val) {
    printf("%s", val.c_str());
}

void ins(vector<string>* num) {
    string val = num->at(1);
    sink(val);
}

int main() {
    vector<string> num;
    prevent_opt(&num);
    ins(&num);
    prevent_opt(&num);
    return 0;
}

