#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;

    void find_sum(vector<int>& v, int target, int st) {
      for (int i = st; i < v.size(); ++i) {
        if (target < v[i]) break;
        else if (target == v[i]) {
          cur.pb(v[i]);
          res.pb(cur);
          cur.pop_back();
          break;
        }
        cur.pb(v[i]);
        find_sum(v, target - v[i], i);
        cur.pop_back();
      }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end()); 
      cur.clear();
      res.clear();
      find_sum(candidates, target, 0);
      return res;
    }
};

int main() {
  Solution slt;
  vector<int> n = {2,3,5};
  int tar = 8;
  vector<vector<int>> v = slt.combinationSum(n, tar);
  for (auto& i: v) {
    PR("x:");
    for (auto& j: i) {
      PR(j);
    }
  }
  return 0;
}
