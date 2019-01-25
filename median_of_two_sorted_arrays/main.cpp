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
    double direct_find_median(vector<int>& nums1, vector<int>& nums2) {
      nums1.insert(nums1.end(), nums2.begin(), nums2.end());
      sort(nums1.begin(), nums1.end());
      int as = nums1.size();
      int m = (as - 1) >> 1;
      if ((as & 1) == 0) return (float)(nums1[m] + nums1[m + 1]) / 2;
      else return nums1[m];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      if (nums2.size() < nums1.size()) return findMedianSortedArrays(nums2, nums1);

      // a == 0
      int as = nums1.size(), bs = nums2.size();
      int l = (bs - 1) >> 1, r = bs >> 1;
      int m = (as >> 1) + 1;
      if (as == 0) {
        if ((bs & 1) == 0) return (float)(nums2[l] + nums2[r]) / 2;
        else return nums2[l];
      }

      // if case is small, solve directly
      if (as + bs < 12) return direct_find_median(nums1, nums2);

      // as << bs, cut, remove (l - m) elements
      if ((as << 1) + 6 < bs) {
        nums2.erase(nums2.begin() + (bs - l + m), nums2.begin() + bs);
        nums2.erase(nums2.begin(), nums2.begin() + (l - m));
      } else { // compare medium
        int m1 = (as - 1) >> 1;
        int lm = nums1[m1], rm = nums2[r];
        if (lm < rm) {
          nums1.erase(nums1.begin(), nums1.begin() + m1);
          nums2.erase(nums2.begin() + bs - m1, nums2.begin() + bs);
        } else if (rm < lm) {
          nums1.erase(nums1.begin() + as - m1, nums1.begin() + as);
          nums2.erase(nums2.begin(), nums2.begin() + m1);
        } else return (float)(lm + rm) / 2;
      }
      return findMedianSortedArrays(nums1, nums2);
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 3, 4, 5, 6, 7, 8, 9, 9, 9, 10, 11, 12, 13, 13, 14, 15, 17, 19, 20, 21};
  vector<int> m = {2, 2, 2, 2, 2, 2};
  PR(slt.findMedianSortedArrays(n, m));
  return 0;
}
