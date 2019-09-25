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
    int check_state(int s, char c) {
        if (0 <= c - '0' && c - '0' <= 9) {
            if (s == 0) s = 1;
            else if (s < 4) ;
            else if (s == 4) s = 1;
            else if (s == 5) s = 2;
            else if (s == 6) s = 3;
            else if (s == 7) s = 3;
            else if (s == 9) s = 2;
            else s = -1;
        } else if (c == '+' || c == '-') {
            if (s == 0) s = 4;
            else if (s == 6) s = 7;
            else s = -1;
        } else if (c == '.') {
            if (s == 0 || s == 4) s = 9;
            else if (s == 1) s = 5;
            else s = -1;
        } else if (c == 'e') {
            if (s == 1 || s == 2 || s == 5) s = 6; 
            else s = -1;
        } else if (c == ' ') {
            if (s == 0) ;
			else if (s < 4 || s == 5 || s == 8) s = 8;
            else s = -1;
        } else {
            s = -1;
        }
        return s;
    }    

    bool isNumber(string s) {
        int state = 0;
        for (int i = 0; i < s.length(); ++i) {
            state = check_state(state, s[i]);
            if (state < 0) break;
        }
        return state == 1 || state == 2 || state == 3 || state == 5 || state == 8;
    }
};

int main() {
  Solution slt;
  string s = "46.e3";
  PR(slt.isNumber(s));
  return 0;
}
