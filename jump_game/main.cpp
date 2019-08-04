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
  bool can_reach[1000000];
  Solution() {
    memset(can_reach, 0, sizeof can_reach);
  }

  bool canJump(vector<int>& nums) {
    can_reach[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
      if (can_reach[i]) {
        for (int j = min((int)nums[i], (int)nums.size() - i - 1); 0 < j; --j) {
          if (can_reach[i + j]) break;
          can_reach[i + j] = true;
          if (i + j == nums.size() - 1) return true;
        }
      } else return false;
    }   
    if (can_reach[nums.size() - 1] ) return true;
    return false;
  }
};

int main() {
  Solution slt;
  vector<int> n = {3, 2, 1, 0, 4};
  PR(slt.canJump(n));
  return 0;
}
