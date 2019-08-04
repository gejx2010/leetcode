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
  void visit(vector<vector<int>>& matrix, int lr, vector<int>& res) {
    int r = matrix.size();
    int l = matrix[0].size();
    if (((min(r, l) - 1) >> 1) < lr) return;
    int rb = lr, lb = lr;
    // visit top left - down
    for (int i = lb; i < l - lb; ++i) 
      res.pb(matrix[rb][i]);
    int cl = l - lb - 1;
    // visit right top - down
    for (int i = rb + 1; i < r - rb; ++i) 
      res.pb(matrix[i][cl]);
    int cr = r - rb - 1;
    if (cr != rb) {
      for (int i = cl - 1; lb <= i; --i) 
        res.pb(matrix[cr][i]);
    }
    if (cl != lb) {
      for (int i = cr - 1; lr < i; --i) 
        res.pb(matrix[i][lb]);
    }
    visit(matrix, lr + 1, res);
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.size() <= 0) return res;
    // visit outer
    visit(matrix, 0, res);
    return res;
  }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  PRV(slt.spiralOrder(n));
  return 0;
}
