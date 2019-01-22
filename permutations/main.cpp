#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <set>
#include <algorithm>

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

    void per_on_set(set<int> s) {
      if (s.empty()) { res.pb(cur); return; }
      for (auto it: s) {
        set<int> ns(s);
        ns.erase(it);
        cur.push_back(it);
        per_on_set(ns);
        cur.pop_back();
      }
    }

    vector<vector<int>> permute(vector<int>& nums) {
      set<int> s(nums.begin(), nums.end()); 
      res.clear();
      cur.clear();
      per_on_set(s);
      return res;
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 2, 3};
  for (auto& it: slt.permute(n)) {
    PR("x:");
    for (auto& v: it) PR(v);
  }
  return 0;
}
