#include <iostream>
#include <set>
#include <utility>

using namespace std;

int main() {
  set<int> v = {1,2,3};
  decltype(v) x = v;
  x.erase(1);
  for (auto n: x) printf("n: %d\n", n);
  for (auto vv: v) printf("vv: %d\n", vv);
  return 0;
}
