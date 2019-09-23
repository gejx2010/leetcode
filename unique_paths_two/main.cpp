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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        if (n == 0) return 0;
        vector<vector<long long>> sv(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (obstacleGrid[i - 1][j - 1]) sv[i][j] = 0;
                else if (i == 1 && j == 1) sv[i][j] = 1;
                else sv[i][j] = sv[i - 1][j] + sv[i][j - 1];
            }
        }
        return sv[m][n];
    }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {{0,0,0},
                           {0,0,0}};
  PR(slt.uniquePathsWithObstacles(n));
  return 0;
}
