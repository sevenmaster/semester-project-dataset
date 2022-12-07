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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

void __attribute__ ((noinline)) sink(string val) {
    printf("%s", val.c_str());
}

vector<string> ins(vector<string> num, int pos) {
    sink(num.at(pos));
    return num;
}

vector<string> D(vector<string> num, int pos) {
    return ins(num, pos - 5);
}

vector<string> C(vector<string> num, int pos) {
    return D(num, pos * 2);
}

vector<string> B(vector<string> num, int pos) {
    return C(num, pos + 1);
}

vector<string> A(vector<string> num, int pos) {
    return B(num, pos / 2);
}

int main() {
    int pos = nolibrand();
    vector<string> num;
    prevent_opt(&num);
    num = A(num, pos);
    prevent_opt(&num);
    return 0;
}

