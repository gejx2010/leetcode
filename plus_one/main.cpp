#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ":" << endl; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int i;
    for (i = digits.size() - 1; 0 <= i; --i) {
        if (digits[i] < 9) { ++digits[i]; break; }
        else digits[i] = 0;
    } 
    PR(i);
    PRV(digits);
    if (i < 0 && digits[0] == 0) digits.insert(digits.begin(), 1);
    return digits;
  }
};

int main() {
  vector<int> n = {9, 9, 9};
  Solution slt;
  for (auto& it: slt.plusOne(n))
    cout << it << " ";
  cout << endl;
  return 0;
}
