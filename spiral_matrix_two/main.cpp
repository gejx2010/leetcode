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
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res;
    if (n <= 0) return res;
    for (int i = 0; i < n; ++i) {
      res.push_back(vector<int>(n, 0));
    }
    int cn = 0, num = 0;
    while (cn < n) {
      if (n - 2 * cn == 1) {
        res[cn][cn] = n * n;
      } else {
        int st = cn, ed = n - cn - 1;
        int sz = ed - st;
        // draw up
        for (int j = st; j < ed; ++j) res[st][j] = ++num;
        // draw right
        for (int j = st; j < ed; ++j) res[j][ed] = ++num;
        // draw down
        for (int j = ed; st < j; --j) res[ed][j] = ++num;
        // draw left
        for (int j = ed; st < j; --j) res[j][st] = ++num;
      }
      ++cn;
    }
    return res;
  }
};

int main() {
  Solution slt;
  int n = 5;
  for (auto v: slt.generateMatrix(n)) {
    for (auto x: v) printf("%d ", x);
    printf("\n");
  }
  return 0;
}
