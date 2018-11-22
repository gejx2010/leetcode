#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    string addBinary(string a, string b) {
      string res;
      cout << "res:" << res << endl;
      if (a.size() < b.size()) return addBinary(b, a);
      int c = 0, d = 0; 
      for (int i = 0; i < a.size(); ++i) {
        int ka = a.size() - i - 1;
        int kb = b.size() - i - 1;
        int bt = (kb < 0) ? 0 : (b[kb] - '0');
        d = (a[ka] - '0') + bt + c;
        c = d / 2;
        d = d % 2;
        res = to_string(d) + res;
        cout << "res:" << res << endl;
      }
      if (c) res = "1" + res;
      return res;
    }
};

int main() {
  string a = "0", b = "0";
  Solution slt;
  cout << slt.addBinary(a, b) << endl;
  return 0;
}
