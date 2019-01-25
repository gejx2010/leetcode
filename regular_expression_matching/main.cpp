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
    set<pair<int, int>> mark;

    bool isMatch(string s, string p) {
      mark.clear();
      int sl = s.length(), pl = p.length();
      stack<pair<int, int>> st;
      s = "$" + s;
      p = "$" + p;
      st.push(mp(1, 1));
      PR(sl);
      PR(pl);
      while (!st.empty()) {
        auto t = st.top();
        int l = t.first, r = t.second;
        if (!mark.count(t)) mark.insert(mp(l, r));
        else continue;
        st.pop();
        PR(l);
        PR(r);
        PR(s[l]);
        PR(p[r]);
        if (l == sl + 1 && r == pl + 1) return true;
        if (l <= sl) {
          if (r <= pl) {
            if (p[r] == '.') {
              if (r < pl && p[r + 1] == '*') st.push(mp(l, r + 2));
              st.push(mp(l + 1, r + 1));
            } else if (p[r] == '*') {
              st.push(mp(l - 1, r + 1));
              st.push(mp(l, r + 1));
              while (l <= sl && (p[r - 1] == s[l] || p[r - 1] == '.')) st.push(mp(++l, r + 1));
            } else {
              if (s[l] == p[r]) st.push(mp(l + 1, r + 1));
            }
          }
        } else {
          if (pl < r) return true;
          else if (p[r] == '*') st.push(mp(l, r + 1));
          else if (r < pl && p[r + 1] == '*') st.push(mp(l, r + 2));
        }
      }
      return false;
    }
};

int main() {
  Solution slt;
  string s = "";
  string p = ".*";
  PR(slt.isMatch(s, p));
  return 0;
}
