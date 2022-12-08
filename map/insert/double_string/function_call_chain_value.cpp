#include <iostream>
#include <map>


using namespace std;

void __attribute__ ((noinline)) prevent_opt(map<double, string>* num) {
    for (int j = 0; j < rand(); j++) {
        num->insert(make_pair(j, to_string(j)));
    }
    for (auto it = num->begin(); it != num->end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
}

int __attribute__ ((noinline)) nolibrand() {
    return rand();
}

map<double, string> ins(map<double, string> num, const double key, const string value) {
    num[key] = value;
    return num;
}

map<double, string> D(map<double, string> num, const double key, string value) {
    return ins(num, key / 2, value + "A");
}

map<double, string> C(map<double, string> num, const double key, string value) {
    return D(num, key + 2, value + "A");
}

map<double, string> B(map<double, string> num, const double key, string value) {
    return C(num, key * 2, value + "A");
}

map<double, string> A(map<double, string> num, const double key, string value) {
    return B(num, key + 1, value + "A");
}

int main() {
    map<double, string> m;
    prevent_opt(&m);
    m = A(m, 14.14, "Hi");
    prevent_opt(&m);
    return 0;
}

