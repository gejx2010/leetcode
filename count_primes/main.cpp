#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRA(x,i,sz) cout << #x << ": "; for (int i = 0; i < (sz); i++) cout << x[i] << ' '; cout << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int countPrimes(int n) {
        bool* mark = new bool[n + 1];
        memset(mark, true, n + 1);
        int ini = 2;
        while (ini <= n) {
          cout << "ini:" << ini << endl;
          int c = ini << 1;
          while (c <= n) {
            mark[c] = false;
            c += ini;
          }
          for (++ini; ini <= n; ++ini) {
            if (mark[ini]) break;
          }
        }
        int cnt = 0;
        for (int j = 2; j <= n; ++j)
          if (mark[j])
            cnt++;
        return cnt;
    }
};

int main() {
  //vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  int n = 100;
  Solution slt;
  cout << slt.countPrimes(n) << endl;
  return 0;
}
