#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;


void __attribute__ ((noinline)) prevent_opt(vector<string>* num) {
    // insert a random number of elements into num
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

void ins(vector<string>* num, int pos) {
    sink(num->at(pos));
}

void D(vector<string>* num, int pos) {
    ins(num, pos - 5);
}

void C(vector<string>* num, int pos) {
    D(num, pos * 2);
}

void B(vector<string>* num, int pos) {
    C(num, pos + 1);
}

void A(vector<string>* num, int pos) {
    B(num, pos / 2);
}

int main() {
    int val = nolibrand();
    vector<string> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}
