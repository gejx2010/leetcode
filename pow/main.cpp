#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <set>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

typedef long long ll;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
  double myPow(double x, ll n) {
    if (n == 0) return 1.0f;
    if (n < 0) return 1.0f / myPow(x, -n);
    double res = 1.0f;
    while (n) {
      if (n & 1) res *= x;
      x *= x;
      n >>= 1;
      PR(n);
    }
    return res;
  }
};

int main() {
  Solution slt;
  double x = 1.0f;
  int n = -2147483647;
  PR(slt.myPow(x, n));
  return 0;
}
