#include <set>
#include <cstdlib>
#include <random>

using namespace std;

struct xy {
    int x;
    int y;
};

bool operator<(const xy& lhs, const xy& rhs) {
  if (lhs.x != rhs.x) {
    return lhs.x < rhs.x;
  } else {
    return lhs.y < rhs.y;
  }
}

void __attribute__ ((noinline)) prevent_opt(set <xy>* num) {
    for (int i = 0; i < rand(); i++) {
        xy t = {i, i+1};
        num->erase(t);
    }
    for (xy c : *num) {
        printf("%d, %d", c.x, c.y);
    }
}


int main() {
    set<xy> s;
    xy t = {1, 2};
    prevent_opt(&s);
    s.erase(t);
    prevent_opt(&s);
    return 0;
}
