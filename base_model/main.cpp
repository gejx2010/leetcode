#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>

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
  vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  tuple<int, int, int> t = mt(1,2,3);
  int a, b, c;
  tie(a, b, c) = t;
  PR(a); PR(b); PR(c);
  a = 6;
  get<0>(t) = 6;
  PR(get<0>(t));
  PR(get<1>(t));
  PR(get<2>(t));
  return 0;
}
