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

typedef long long ll;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    ll dp[100][100][100];

    void precompute() {
      static int ug[10000];
      static int cc = 0;
      if (0 < cc) return;
      int cnt = 0;
      int cs = 1;
      priority_queue<ll, vector<ll>, greater<ll>> q;
      q.push(1);
      dp[0][0][0] = 1;
      for (int n = 1; cnt < 2000; ++n) { // n = i + j + k
        for (int i = n; cnt < 2000 && 0 <= i; --i) {
          for (int j = 0; cnt < 2000 && j <= n - i; ++j) {
            int k = n - i - j;
            if (0 < i) dp[i][j][k] = (dp[i - 1][j][k] << 1);
            else if (0 < j) dp[i][j][k] = (dp[i][j - 1][k] << 1) + dp[i][j - 1][k];
            else dp[i][j][k] = (dp[i][j][k - 1] << 2) + dp[i][j][k - 1];
            q.push(dp[i][j][k]);
            if (i == n) {
              while (q.top() != dp[n][0][0]) {
                if (0 < q.top()) ug[++cnt] = q.top();
                q.pop();
              }
            }
          }
        }
        PR(n);
        PR(cnt);
      }
    }

    Solution() {
      memset(ug, 0, sizeof ug);
      memset(dp, 0, sizeof dp);
      precompute();
    }    

    int nthUglyNumber(int n) {
      return ug[n]; 
    }
};

int main() {
  Solution slt;
  for (int i = 0; i <= 1690; ++i)
    PR(slt.nthUglyNumber(i));
  return 0;
}
