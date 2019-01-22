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

    void per_on_set(multiset<int> s) {
      if (s.empty()) { res.pb(cur); return; }
      int bef = INT_MIN;
      for (auto it = s.begin(); it != s.end(); ++it) {
        if (bef == *it) continue;
        multiset<int> ns(s);
        auto jit = ns.find(*it);
        ns.erase(jit);
        cur.push_back(*it);
        per_on_set(ns);
        cur.pop_back();
        bef = *it;
      }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
      multiset<int> s(nums.begin(), nums.end()); 
      res.clear();
      cur.clear();
      per_on_set(s);
      return res;
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 1, 2};
  for (auto& it: slt.permuteUnique(n)) {
    PR("x:");
    for (auto& v: it) PR(v);
  }
  return 0;
}
