#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int mySqrt(int x) {
      if (x <= 1) return x;
      int l = 1, r = x;
      while (l < r) {
        long long m = ((long long)l + r) >> 1;
        long long mul = (long long)m * m;
        if (mul < x) l = m + 1;
        else if (x < mul) r = m;
        else return m;
      }
      return r - 1;
    }
};

int main() {
  int ip = 2147483647;
  Solution slt;
  cout << slt.mySqrt(ip) << endl;
  return 0;
}
