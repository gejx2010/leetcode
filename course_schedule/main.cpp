#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

typedef pair<int, int> pri;

#define mp make_pair
#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int a[numCourses][numCourses];
        memset(a, 0, sizeof a);
        set<int> s;
        for (int i = 0; i < numCourses; i++) s.insert(i);
        for (auto& it: prerequisites) 
          a[it.first][it.second] = 1;
        while (!s.empty()) {
          set<int> ss(s);
          bool has_zero_in = false;
          for (auto& it: ss) {
            int cnt_in = 0;
            for (int i = 0; i < numCourses; ++i) cnt_in += a[it][i];
            if (cnt_in == 0) { 
              has_zero_in = true;
              s.erase(it);
              for (int i = 0; i < numCourses; ++i) 
                a[i][it] = 0;
              break;
            }
          }
          if (!has_zero_in) return false;
        }
        return true;
    }

};

int main() {
  vector<pri> n = {{1, 0}, {0, 1}};
  Solution slt;
  PR(slt.canFinish(2, n));
  return 0;
}
