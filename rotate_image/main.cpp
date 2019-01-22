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
    void fill(vector<vector<int>>& matrix, int st) {
      if ((matrix.size() >> 1) <= st) return;
      for (int i = st; i < matrix.size() - st - 1; ++i) {
        int r = matrix.size() - i - 1;
        int e = matrix.size() - st - 1;
        int m = matrix[st][i];
        matrix[st][i] = matrix[r][st];
        matrix[r][st] = matrix[e][r];
        matrix[e][r] = matrix[i][e];
        matrix[i][e] = m;
      }
      fill(matrix, st + 1);
    }

    void rotate(vector<vector<int>>& matrix) {
      fill(matrix, 0);
    }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {
  {1,2,3},
  {4,5,6},
  {7,8,9}
  };
  slt.rotate(n);
  for (auto& it: n) {
    PR("x");
    for (auto& v: it) {
      PR(v);
    }
  }
  return 0;
}
