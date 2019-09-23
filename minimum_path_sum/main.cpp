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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> sv(m + 1, vector<int>(n + 1, 0));
        sv[1][1] = grid[0][0];
        for (int i = 2; i <= n; ++i) sv[1][i] = grid[0][i - 1] + sv[1][i - 1];
        for (int i = 2; i <= m; ++i) sv[i][1] = grid[i - 1][0] + sv[i - 1][1];
        for (int i = 2; i <= m; ++i)
            for (int j = 2; j <= n; ++j)
                sv[i][j] = min(sv[i][j - 1], sv[i - 1][j]) + grid[i - 1][j - 1];
        return sv[m][n];
    }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {{1, 2, 5},
                           {3, 2, 1}};
  PR(slt.minPathSum(n));
  return 0;
}
