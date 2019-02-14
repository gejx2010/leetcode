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
    bool isUgly(int num) {
      if (num <= 0) return 0;
      while ((num & 1) == 0) num >>= 1; 
      while (num % 3 == 0) num /= 3;
      while (num % 5 == 0) num /= 5;
      return (num == 1);
    }
};

int main() {
  Solution slt;
  int n = 14;
  PR(slt.isUgly(n));
  return 0;
}
