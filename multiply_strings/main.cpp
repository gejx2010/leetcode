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
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;
#define num(a) (((a) < '0') ? 0 : (int)((a) - '0'))
#define chr(a) (char)('0' + (a))

class Solution {
public:

    int cmulti(char a, char b) {
      return num(a) * num(b);
    }

    string multiply(string num1, string num2) {
      reverse(num1.begin(), num1.end());
      reverse(num2.begin(), num2.end());
      int lsz = num1.size(), rsz = num2.size();
      int bsz = (lsz + rsz) << 1;
      char s[rsz][bsz];
      memset(s, 0, sizeof s);
      for (int i = 0; i < num2.size(); ++i) {
        for (int j = 0; j < i + num1.size(); ++j) {
          if (j < i && 0 < i) {
            s[i][j] = s[i - 1][j];
          } else if (i <= j) {
            int c = cmulti(num2[i], num1[j - i]);
            c += num(s[i][j]);
            if (0 < i) c += num(s[i - 1][j]);
            if (c == 0) s[i][j] = '0';
            else {
              int rk = j;
              while (c) {
                s[i][rk] = chr(c % 10);
                c /= 10;
                ++rk;
              }
            }
          }
        }
      }
      int rk = bsz - 1;
      while (0 <= rk && num(s[rsz - 1][rk]) == 0) --rk;
      string res = "0";
      if (rk < 0) return res;
      res = string(s[rsz - 1], rk + 1);
      reverse(res.begin(), res.end());
      return res;
    }
};

int main() {
  Solution slt;
  string a = "100001";
  string b = "12200007";
  PR(slt.multiply(a, b));
  return 0;
}
