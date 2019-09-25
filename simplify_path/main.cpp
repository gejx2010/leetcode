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
    string simplifyPath(string path) {
        vector<string> p;
        for (int i = 0; i < path.length(); ) {
            // accept /
            while (path[i] == '/') ++i;
            if (path.length() <= i) break;
            string cc = "";
            if (path[i] == '.') {
                cc += path[i];
                ++i;
                if (path[i] == '.') {
                    cc += path[i];
                    ++i;
                    if (path[i] == '/' || i == path.length()) {
                        if (!p.empty()) p.pop_back();
                        continue;
                    } else {

                    }
                } else if (path[i] == '/' || i == path.length()) {
                    continue; 
                } else {

                }
            }
            while (i < path.length() && path[i] != '/') {
                cc += path[i];
                ++i;
            }
            p.push_back(cc);
        }
        if (p.empty()) return "/";
        string res;
        for (auto v: p) {
            res += "/" + v;
        }
        return res;
    }
};

int main() {
  Solution slt;
  string path = "/.";
  PR(slt.simplifyPath(path));
  return 0;
}
