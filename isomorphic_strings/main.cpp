#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define make_pair mp
#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if (s.length() == 0) return true; 
       map<char, char> m;
       map<char, bool> e;
       for (int i = 0; i < s.length(); i++) {
         if (m.count(s[i]) == 0) {
           if (e.count(t[i]) == 0) {
             m[s[i]] = t[i];
             e[t[i]] = true;
           } else return false;
         } else if (m[s[i]] != t[i]) return false;
       }
       return true;
    }
};

int main() {
  string s = "ab", t = "aa";
  Solution slt;
  cout << slt.isIsomorphic(s, t) << endl;
  return 0;
}
