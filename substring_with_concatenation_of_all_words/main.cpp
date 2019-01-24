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
#include <string>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
       vector<int> res;
       if (words.empty()) return res;

       int fl = words[0].size();
       int asz = words.size();
       int tl = fl * asz;
       map<string, int> wm; 
       map<string, int> wc;
       int rk = 0;
       for (auto s: words) {
         wm[s] = rk;
         if (!wc.count(s)) wc[s] = 1;
         else ++wc[s];
         ++rk;
       }

       multimap<int, int> pm;
       set<int> dst;
       for (int i = 0; i < s.length() - tl + 1; ++i) 
         dst.insert(i);
       string cstr = "";
       int tst = 0;
       int st = 0;
       set<int> sres;
       while (!dst.empty()) {
         tst = *(dst.begin());
         st = tst;
         dst.erase(tst);
         pm.clear();
         PR(tst);
         PR(dst.size());
         for (int i = tst; i < s.length() && tst < s.length() - tl + 1; ++i) {
           cstr += s[i];
           PR(tst);
           PR(st);
           PR(cstr);
           if (i - st + 1 == fl) {
             if (wm.count(cstr)) {
               if (wc[cstr] == pm.count(wm[cstr])) {
                 auto it = pm.find(wm[cstr]);
                 tst = (*it).second + fl;
                 dst.erase(tst);
                 decltype(pm) npm;
                 for (auto& n: pm) 
                   if (tst <= n.second) npm.insert(n);
                 pm = npm;
               }
               pm.insert(mp(wm[cstr], st));
               if (pm.size() == asz) sres.insert(tst);
               st = i + 1;
               cstr = "";
             } else {
               i = tst;
               ++tst;
               dst.erase(tst);
               st = tst;
               cstr = ""; 
               pm.clear();
             }
           }
         }
       }
       for (auto v: sres) res.push_back(v);
       return res;
    }
};

int main() {
  Solution slt;
  string s = "aaaaaaaa";
  vector<string> words = {"aa","aa","aa"};
  PRV(slt.findSubstring(s, words));
  return 0;
}
