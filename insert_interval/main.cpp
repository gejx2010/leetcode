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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      vector<vector<int>> res;
      if (intervals.empty()) { res.push_back(newInterval); return res; }
      int nis = newInterval[0], nie = newInterval[1];
      bool ht = false, track = false;
      int rk = 0;
      int st, ed;
      for (auto v: intervals) {
        int cs = v[0], ce = v[1];
        if (!track) {
          // test start
          if (!ht) {
            if (nis < cs) {
              ht = true;
              st = nis;
            } else if (nis <= ce) {
              ht = true;
              st = cs;
            } else {
              res.push_back(v);
            }
          }

          if (ht) {
            if (nie < cs) {
              track = true;
              res.push_back({st, nie});
              res.push_back(v);
            } else if (nie <= ce) {
              track = true;
              res.push_back({st, ce});
            } else {
            }
          }
        } else {
          res.push_back(v);
        }
      }
      if (!track) {
        if (!ht) { st = nis; }
        res.push_back({st, nie});
      }
      return res;
    }
};

int main() {
  Solution slt;
  vector<vector<int>> n = {{1,2},{3,5},{6,7},{8,10},{12,16}};
  vector<int> nn = {4,8};
  for (auto v: slt.insert(n, nn)) {
    printf ("(%d, %d)\n", v[0], v[1]);
  }
  return 0;
}
