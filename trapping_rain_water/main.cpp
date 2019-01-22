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
    int trap(vector<int>& height) {
      int l = 0, r = height.size() - 1; 
      int sum = 0;
      while (l < r) {
        if (height[l] <= height[r]) {
          int csum = 0, i = 0;
          for (i = l + 1; i <= r; ++i) {
            if (height[l] <= height[i]) break;
            csum += height[i];
          }
          sum += height[l] * (i - l - 1) - csum;
          l = i;
        } else {
          int csum = 0, i = 0;
          for (i = r - 1; l <= i; --i) {
            if (height[r] <= height[i]) break;
            csum += height[i];
          }
          sum += height[r] * (r - i - 1) - csum;
          r = i;
        }
      }
      return sum;
    }
};

int main() {
  Solution slt;
  vector<int> n = {0,1,0,2,1,0,1,3,2,1,2,1};
  PR(slt.trap(n));
  return 0;
}
