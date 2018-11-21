#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
       if (s.empty()) return 0;
       int res = 0;
       int i = s.length() - 1;
       while (s[i] == ' ') --i;
       for (; 0 <= i; --i) {
         if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) ++res;
         else break;
       }
       return res;
    }
};

int main() {
  string s = "a";
  Solution slt;
  cout << slt.lengthOfLastWord(s) << endl;
  return 0;
}
