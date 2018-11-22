#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int lower_bound(vector<int>& a, int target) {
      int l = 0, r = a.size() - 1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (a[m] < target) l = m + 1;
        else r = m - 1;
      }
      if (r + 1 == a.size() || a[r + 1] != target) return -1;
      return r + 1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() <= 0) 
          return vector<int>{-1, -1};
        vector<int> res;
        int low = lower_bound(nums, target);
        res.push_back(low);
        if (low == -1) {
          res.push_back(-1);
        } else {
          int i = low + 1;
          for (; i < nums.size(); ++i) {
            if (nums[i] != target) {
              res.push_back(i - 1);
              break;
            }
          }
          if (i == nums.size()) res.push_back(nums.size() - 1);
        }
        return res;
    }
};

int main() {
  vector<int> n = {5,7,7,8,8,10};
  int target = 6;
  Solution slt;
  vector<int> rr = slt.searchRange(n, target);
  PRV(rr);
  return 0;
}
