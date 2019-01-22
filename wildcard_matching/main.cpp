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
    bool match[1000][1000];

    bool is_empty(string p) {
      for (int i = 0; i < p.length(); ++i) 
        if (p[i] != '*') return false;
      return true;
    }

    bool isMatch(string s, string p) { 
      if (s.empty()) return is_empty(p);
      if (p.empty()) return is_empty(s);
      memset(match, 0, sizeof match);
      match[0][0] = true;
      for (int i = 1; i <= p.length(); ++i) {
        for (int j = 1; j <= s.length(); ++j) {
          if (p[i - 1] == '?') {
            match[i][j] = match[i - 1][j - 1];
          } else if (p[i - 1] == '*') {
            match[i][j - 1] = (match[i - 1][j - 1] || match[i][j - 1]);
            match[i][j] = (match[i - 1][j - 1] || match[i - 1][j] || match[i][j - 1]);
          } else {
            match[i][j] = (match[i - 1][j - 1] && (p[i - 1] == s[j - 1]));
          }
        }
      }
      return match[p.length()][s.length()];
    }
};

int main() {
  Solution slt;
  string s = "aa";
  string p = "*";
  PR(slt.isMatch(s, p));
  return 0;
}
