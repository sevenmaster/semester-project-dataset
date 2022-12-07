#include <string>
#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

void __attribute__ ((noinline)) prevent_opt(vector<string>* num, string val) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        num->push_back(to_string(i));
    }
    //print a random element into num
    string a = num->at(rand());
    printf("%s,%s", val.c_str(), a.c_str());
}

int main() {
    vector<string> num;
    string val = "Hello World";
    prevent_opt(&num, val);
    val = num.at(1);
    prevent_opt(&num, val);
    return 0;
}

