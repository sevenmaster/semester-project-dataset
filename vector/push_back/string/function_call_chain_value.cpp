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

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

vector<string> ins(vector<string> num, string val) {
    num.push_back(val);
    return num;
}

vector<string> D(vector<string> num, string val) {
    return ins(num, val + "d");
}

vector<string> C(vector<string> num, string val) {
    return D(num, val + "b");
}

vector<string> B(vector<string> num, string val) {
    return C(num, val + "b");
}

vector<string> A(vector<string> num, string val) {
    return B(num, val + "a");
}

string __attribute__ ((noinline)) randStr() {
    return to_string(rand());
}

int main() {
    string val = randStr();
    vector<string> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}


