#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if (nums.size() == 0) return 0;
      int ss = 0;
      int min_len = 0;
      int st = 0;
      for (int i = 0; i < nums.size(); ++i) {
        ss += nums[i];
        while (s <= ss - nums[st]) ss -= nums[st++];
        if (s <= ss && (min_len == 0 || i - st + 1 < min_len)) min_len = i - st + 1;
      }
      return min_len;
    }
};

int main() {
  vector<int> n = {12,28,83,4,25,26,25,2,25,25,25,12};
  int s = 213;
  Solution slt;
  PR(slt.minSubArrayLen(s, n));
  return 0;
}
