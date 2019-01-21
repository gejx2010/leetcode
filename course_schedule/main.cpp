#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>

using namespace std;

typedef pair<int, int> pri;

#define mp make_pair
#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    int *mark;
    int *finish;
    multimap<int, int> m;

    bool dfs(int i) {
      auto p = m.equal_range(i);
      mark[i] = 1;
      for (auto it = p.first; it != p.second; ++it) {
        if (!mark[it->second]) {
          bool res = dfs(it->second);
          if (!res) return res;
        } else if (!finish[it->second]) {
          return false;
        }
      }
      finish[i] = 1;
      return true;
    }

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        mark = new int[numCourses];
        finish = new int[numCourses];
        memset(mark, 0, sizeof(int) * numCourses);
        memset(finish, 0, sizeof(int) * numCourses);
        // read in
        for (auto& it: prerequisites) 
          m.insert(mp(it.second, it.first));
        // search untrack
        for (int i = 0; i < numCourses; ++i) {
          if (mark[i] == 0) 
            if (!dfs(i)) return false;
        }
        delete[] mark;
        delete[] finish;
        return true;
    }
};

int main() {
  vector<pri> n = {{1, 0}, {2, 6}, {1, 7}, {6, 4}, {7, 0}, {0,5}};
  Solution slt;
  PR(slt.canFinish(8, n));
  return 0;
}
