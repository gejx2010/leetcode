#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
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
  vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  Solution slt;
  cout << slt.maxSubArray(n) << endl;
  return 0;
}
