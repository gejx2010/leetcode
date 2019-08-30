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
  vector<int> st;

  Solution() {
    st = vector<int>(10, 0);
    st[0] = 1;
    for (int i = 1; i < 10; ++i) {
      st[i] = st[i - 1] * i;
    }
  }

  string getPermutation(int n, int k) {
    --k;
    vector<int> vec;
    for (int i = 0; i < n; ++i) vec.push_back(i + 1);
    string res = "";
    int cp = n;
    while (cp > 1) {
      --n;
      int m = k / st[n];
      res += to_string(vec[m]);
      vec.erase(vec.begin() + m);
      k %= st[n];
      --cp;
    }
    res += to_string(vec[0]);
    return res;
  }
};

int main() {
  Solution slt;
  int n = 4, k = 9;
  PR(slt.getPermutation(n, k));
  return 0;
}
