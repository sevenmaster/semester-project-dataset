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

string __attribute__ ((noinline)) randStr() {
    return to_string(rand());
}

int main() {
    string val = randStr();
    vector<string> num;
    prevent_opt(&num);
    ins(&num, val);
    prevent_opt(&num);
    return 0;
}

