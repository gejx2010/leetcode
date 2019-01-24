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
    int longestValidParentheses(string s) {
       stack<int> st;
       int cnt = 0;
       int cl[s.length() + 1];
       memset(cl, 0, sizeof cl);
       for (int i = 0; i < s.length(); ++i) {
         if (s[i] == '(') st.push(i);
         else {
           if (!st.empty()) {
             int t = st.top();
             int ll = i - t + 1 + cl[t];
             cnt = max(cnt, ll);
             cl[i + 1] = ll;
             st.pop();
           }
         }
       }
       return cnt;
    }
};

int main() {
  Solution slt;
  string s = ")()())";
  PR(slt.longestValidParentheses(s));
  return 0;
}
