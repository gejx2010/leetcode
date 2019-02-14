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
    vector<vector<int>> tms;

    bool isMatch(string s, string p) {
      tms.clear();
      int sl = s.length(), pl = p.length();
      for (int i = 0; i <= pl; ++i) {
        vector<int> v;
        for (int j = 0; j <= sl; ++j) v.pb(0);
        tms.pb(v);
      }
      tms[0][0] = true;
      p = '$' + p;
      s = '$' + s;
      for (int i = 1; i <= pl; ++i) {
        for (int j = 0; j <= sl; ++j) {
          if (p[i] == s[j] || p[i] == '.') {
            tms[i][j] = (1 <= j && tms[i - 1][j - 1]);
          } else if (p[i] == '*') {
            tms[i][j] = ((1 <= j && tms[i - 1][j - 1] || tms[i][j - 1]) && (p[i - 1] == s[j] || p[i - 1] == '.')) ||
                (tms[i - 2][j]) || (tms[i - 1][j]);
          }
        }
      }
      return tms[pl][sl];
    }
};

int main() {
  Solution slt;
  string s = "a";
  string p = "ac";
  PR(slt.isMatch(s, p));
  return 0;
}
