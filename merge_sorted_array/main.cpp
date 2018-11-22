#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m - 1, j = n - 1, k = n + m - 1;
      while (true) {
        while (0 <= i && (j < 0 || nums2[j] < nums1[i])) {
          nums1[k--] = nums1[i--];
        }
        while (0 <= j && (i < 0 || nums1[i] <= nums2[j])) {
          nums1[k--] = nums2[j--];
        }
        if (i < 0) break;
      }
    }
};

int main() {
  vector<int> a = {2,0};
  vector<int> b = {1};
  Solution slt;
  slt.merge(a, 1, b, 1);
  PRV(a);
  return 0;
}
