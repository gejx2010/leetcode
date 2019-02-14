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
  void visit(vector<vector<int>>& matrix, int lr, vecotr<int>& res) {
    int r = matrix.size();
    int l = matrix[0].size();
    int ll = l >> 1;
    if (ll <= lr) return;
    int rb = lr, lb = lr, cr = rb, cl = lb;
    // visit top left - down
    for (int i = rb; i < l - rb - 1; ++i) {
      res.pb(matrix[rb][i]);
    }
    cl = l - 1 - lr;
    // visit right top - down
    for (int i = rb; i < r - rb - 1; ++i) {
      res.pb(matrix[i][lb]);
    }
  }

  vector<int> spiralOrder(vector<vecotr<int>>& matrix) {
    vector<int> res;
    if (matrix.size() <= 0) return res;
    // visit outer
    visit(matrix, 0, res);
  }
};

int main() {
  Solution slt;
  vector<int> n = {1, 2, 3};
  PR(slt.maxSubArray(n));
  return 0;
}
