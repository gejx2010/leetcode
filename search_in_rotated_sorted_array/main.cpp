#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
          int m = (l + r) >> 1;
          PR(l);
          PR(r);
          PR(m);
          if (nums[l] < nums[m]) {
            if (target < nums[m]) {
              if (nums[l] < target) r = m;
              else if (target < nums[l]) l = m + 1;
              else return l;
            } else if (nums[m] < target) l = m + 1;
            else return m;
          } else {
            if (target < nums[m]) r = m;
            else if (nums[m] < target) {
              if (target < nums[l]) l = m + 1;
              else if (nums[l] < target) r = m;
              else return l;
            } else return m;
          }
        }
        if (nums.size() <= l || nums[l] != target) return -1;
        return l;
    }
};

int main() {
  vector<int> n = {3, 1};
  int target = 3;
  Solution slt;
  cout << slt.search(n, target) << endl;
  return 0;
}
