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
  bool acol[10000];
  bool arow[10000];
  bool aleft[40000];
  bool aright[40000];
  int num;
  vector<vector<string>> res;
  vector<pair<int,int>> path;

  Solution() {
    memset(acol, 0, sizeof acol);
    memset(arow, 0, sizeof arow);
    memset(aleft, 0, sizeof aleft);
    memset(aright, 0, sizeof aright);
    res.clear();
  }

  vector<string> path2string(vector<pair<int,int>> path) {
    vector<string> r;
    for (int i = 0; i < num; ++i) {
      string s = "";
      for (int j = 0; j < num; ++j) {
        if (j == path[i].second) s += "Q";
        else s += ".";
      }
      r.push_back(s);
    }
    return r;
  }

  void backtrack(int row) {
    cout << "backtrack row:" << row << endl;
    for (int i = 0; i < num; ++i) {
      if (!acol[i] && !aleft[row - i + num] && !aright[row + i]) {
        if (row == num - 1) {
          path.emplace_back(make_pair(row, i));
          res.push_back(path2string(path));
          cout << "Get solution here:" << endl;
          for (auto p: path) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
          }
          cout << "End solution";
          path.pop_back();
          break;
        }
        // add mark
        acol[i] = true;
        aleft[row - i + num] = true;
        aright[row + i] = true;
        path.emplace_back(make_pair(row, i));
        // track next row
        backtrack(row + 1);
        // clean mark
        path.pop_back();
        aright[row + i] = false;
        aleft[row - i + num] = false;
        acol[i] = false;
      }
    }
    cout << "end backtrack row:" << row << endl;
  }

  vector<vector<string>> solveNQueens(int n) {
    num = n;
    path.clear();
    backtrack(0);
    return res;
  }
};

int main() {
  Solution slt;
  int n = 10;
  vector<vector<string>> r = slt.solveNQueens(n);
  int rank = 1;
  for (auto rr: r) {
    cout << "begin solution" << rank << endl;
    for (auto s: rr) {
      cout << s << endl;
    }
    cout << "end solution" << rank << endl;
    rank += 1;
  }
  return 0;
}
