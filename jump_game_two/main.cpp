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
    int jump_step(vector<int>& nums, int l, int r) {
      if (nums.size() - 1 <= r) return 0;
      int mx = r + 1;
      for (int i = l; i <= r; ++i) {
        mx = max(i + nums[i], mx);
      }
      return jump_step(nums, r + 1, mx) + 1;
    }

    int jump(vector<int>& nums) {
      return jump_step(nums, 0, 0);   
    }
};

int main() {
  Solution slt;
  vector<int> n = {2, 3, 1, 1, 4};
  PR(slt.jump(n));
  return 0;
}
