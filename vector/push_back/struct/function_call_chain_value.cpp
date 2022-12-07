#include <stdlib.h>
#include <cstdio>
#include <vector>
using namespace std;

struct xy {
    int x;
    int y;
};

void __attribute__ ((noinline)) prevent_opt(vector<xy>* num) {
    // insert a random number os elements into num
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i+1};
        num->push_back(t);
    }
    //print a random element into num
    xy a = num->at(rand());
    printf("%d,%d", a.x, a.y);
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

vector<xy> ins(vector<xy> num, xy val) {
    num.push_back(val);
    return num;
}

vector<xy> D(vector<xy> num, xy val) {
    val.x = val.x - 2;
    val.y = val.y - 2;
    return ins(num, val);
}

vector<xy> C(vector<xy> num, xy val) {
    val.x = val.x * 2;
    val.y = val.y * 2;
    return D(num, val);
}

vector<xy> B(vector<xy> num, xy val) {
    val.x = val.x + 2;
    val.y = val.y + 2;
    return C(num, val);
}

vector<xy> A(vector<xy> num, xy val) {
    val.x = val.x / 2;
    val.y = val.y / 2;
    return B(num, val);
}

int main() {
    int a = nolibrand();
    xy val = {a, a + 1};
    vector<xy> num;
    prevent_opt(&num);
    num = A(num, val);
    prevent_opt(&num);
    return 0;
}


