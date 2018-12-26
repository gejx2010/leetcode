#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
  int each_sum(int n) {
    int sum = 0;
    while (0 < n) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }

  bool is_happy(int n) {
    map<int, int> loop;
    bool is_loop = false;
    while (true) {
      loop[n] = 1;
      int sum = each_sum(n);
      printf("sum: %d\n", sum);
      if (sum == 1) return true;
      if (loop.count(sum)) return false;
      n = sum;
    }
    return false;
  }
};

int main() {
  vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  Solution slt;
  cout << slt.is_happy(9) << endl;
  return 0;
}
