#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;


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

void ins(vector<string>* num, string val) {
    num->push_back(val);
}

void D(vector<string>* num, string val) {
    ins(num, val + "d");
}

void C(vector<string>* num, string val) {
    D(num, val + "c");
}

void B(vector<string>* num, string val) {
    C(num, val + "b");
}

void A(vector<string>* num, string val) {
    B(num, val + "a");
}

string __attribute__ ((noinline)) randStr() {
    return to_string(rand());
}

int main() {
    string val = randStr();
    vector<string> num;
    prevent_opt(&num);
    A(&num, val);
    prevent_opt(&num);
    return 0;
}


