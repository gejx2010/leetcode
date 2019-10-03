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
	int find_mark(vector<vector<int>>& matrix) {
		int lb = INT_MIN;
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (matrix[i][j] == lb) {
			i = -1;
			++lb;
			break;
		}
		return lb;
	}

    void setZeroes(vector<vector<int>>& matrix) {
		int lb = find_mark(matrix);
		int m = matrix.size(), n = matrix[0].size();
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) 
				if (matrix[i][j] == 0) {
					for (int k = 0; k < n; ++k) if (matrix[i][k]) matrix[i][k] = lb;
					for (int k = 0; k < m; ++k) if (matrix[k][j]) matrix[k][j] = lb;
				}
		for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) if (matrix[i][j] == lb) matrix[i][j] = 0;
    }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {
  {-2147483648,2,3},
  };
  slt.setZeroes(n);
  for (auto row: n) {
      for (auto e: row) printf("%d ", e);
      printf("\n");
  }
  return 0;
}
