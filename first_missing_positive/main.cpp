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
    int firstMissingPositive(vector<int>& nums) {
      int i = 0;
      for (; i < nums.size(); ++i) 
        if (0 < nums[i] && nums[i] <= nums.size() && nums[i] != i + 1) {
          int m = nums[i];
          nums[i] = nums[m - 1];
          nums[m - 1] = m;
          if (nums[i] != m) --i;
        }
      for (i = 0; i < nums.size(); ++i)
        if (nums[i] != i + 1) 
          break;
      return i + 1;
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 1};
  PR(slt.firstMissingPositive(n));
  return 0;
}
