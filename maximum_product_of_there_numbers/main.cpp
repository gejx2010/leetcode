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
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sz = nums.size();
    return max(nums[0] * nums[1] * nums[sz - 1], nums[sz - 3] * nums[sz - 2] * nums[sz - 1]);
  }
};

int main() {
  Solution slt;
  vector<int> n = {1, 2, 3, -4, 3, -2, 6, 10, 17, -7, -9};
  PR(slt.maximumProduct(n));
  return 0;
}
