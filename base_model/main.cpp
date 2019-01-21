#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      if (nums.empty()) return -1;
      int res = nums[0], sum = 0;
      for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (sum < 0) sum = 0;
        else if (res < sum) res = sum;
      } 
      return res;
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 2, 3};
  PR(slt.maxSubArray(n));
  return 0;
}
