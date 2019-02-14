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
    int maxProduct(vector<int>& nums) {
      int sum = INT_MIN;
      int psum = 1;
      int nsum = 1;
      for (auto n: nums) {
        if (n < 0) {
          int m = psum;
          if (nsum == 1) {
            nsum = psum * n;
            psum = 1;
            sum = max(sum, n); 
          } else {
            psum = nsum * n;
            sum = max(sum, psum);
            nsum = m * n;
          }   
        } else if (n == 0) {
          sum = max(sum, 0); 
          psum = 1;
          nsum = 1;
        } else {
          psum = psum * n;
          nsum = (nsum == 1) ? 1 : nsum * n;
          sum = max(sum, psum);
        }   
      }   
      return sum;
    }   
};

int main() {
  Solution slt;
  vector<int> n = {2,3,-2,4};
  PR(slt.maxProduct(n));
  return 0;
}
