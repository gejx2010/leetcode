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
    vector<vector<string>> res;
    map<vector<int>, int> m;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      int s[26];
      res.clear();
      m.clear();
      int rk = 0;
      for (int i = 0; i < strs.size(); ++i) {
        memset(s, 0, sizeof s);
        for (int j = 0; j < strs[i].size(); ++j) ++s[strs[i][j] - 'a'];
        vector<int> n(s, s + 26);
        if (m.count(n)) {
          res[m[n]].pb(strs[i]);
        } else {
          m[n] = rk;
          ++rk;
          vector<string> cur;
          cur.pb(strs[i]);
          res.pb(cur);
        }
      }
      return res; 
    }

};

int main() {
  Solution slt;
  vector<string> n = {"eat", "tea", "tan", "ate", "nat", "bat"}; 
  for (auto it: slt.groupAnagrams(n)) {
    PR("x");
    for (auto v: it) {
      PR(v);
    }
  }
  return 0;
}
