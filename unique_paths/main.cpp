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

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
  long long count_combo(int t, int s) {
    if (s == 0) return 1;
    long long csum = 1;
    int tt = t, ss = 1;
    long long MAX_NUM = INT_MAX;
    for (int i = 0; i < s; ++i) {
      csum = (csum * tt / ss) % MAX_NUM;
      --tt, ++ss;
    }
    return csum;
  }

  int uniquePaths(int m, int n) {
    int z = min(m, n);
    return count_combo(m + n - 2, z - 1);
  }
};

int main() {
  Solution slt;
  int m = 36, n = 7;
  PR(slt.uniquePaths(m, n));
  return 0;
}
