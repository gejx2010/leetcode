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
    int find_num(vector<int>& nums, int lr, int rr, int ln) {
      if (rr <= lr) return ln;
      if (rr - lr == 1) {
        if (nums[lr] == ln) return ln + 1;
        return ln;
      }
      int m = (lr + rr) >> 1;
      int fn = ln + (m - lr);
      int x = lr, y = rr - 1;
      while (x <= y && x <= m) {
        if (nums[x] < 1 || fn < nums[x]) {
          int mm = nums[x];
          nums[x] = nums[y];
          nums[y] = mm;
          --y;
        } else ++x;
      }
      if (m < x) return find_num(nums, m + 1, rr, fn + 1);
      else return find_num(nums, lr, x, ln);
    }

    int firstMissingPositive(vector<int>& nums) {
      return find_num(nums, 0, nums.size(), 1);
    }
};

int main() {
  Solution slt;
  vector<int> n = {6, 7, 8, 9, 10};
  PR(slt.firstMissingPositive(n));
  return 0;
}
