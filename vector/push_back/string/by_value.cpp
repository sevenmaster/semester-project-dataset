#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

vector<string> ins(vector<string> num) {
    num.push_back("Hello World!");
    return num;
}

void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    // print a
    printf("%s", a.c_str());
}

int main() {
    vector<string> num;
    prevent_opt(&num);
    num = ins(num);
    prevent_opt(&num);
    return 0;
}

