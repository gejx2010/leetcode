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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // get new marks
    vector<vector<int>> marks;
    for (auto p: intervals) {
      int lr = p[0], rr = p[1];
      marks.pb({lr, 0});
      marks.pb({rr, 1});
    } 
    if (marks.size() == 0) return marks;
    sort(marks.begin(), marks.end());
    // sweep line marks
    vector<vector<int>> res;
    int num = 0, st = 0;
    for (auto& p: marks) {
      if (num == 0) st = p[0];
      int mk = p[1];
      if (p[1]) --num;
      else ++num;
      if (num == 0) {
        vector<int> cc = {st, p[0]};
        res.pb(cc);
      }
    }
    return res;
  }
};

int main() {
  Solution slt;
  //vector<vector<int>> n = {{1,3},{2,6},{8,10},{15,18}};
  vector<vector<int>> n = {{1,4},{4,5}};
  vector<vector<int>> res = slt.merge(n);
  for (auto p: res) {
    cout << p[0] << ": " << p[1] << endl;
  }
  return 0;
}
