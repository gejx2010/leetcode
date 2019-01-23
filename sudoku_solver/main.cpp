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

typedef pair<int,int> pri;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;
#define LCOM 3
#define COM 9
#define is_empty(x) ((x) == '.')
#define num(x) ((x) - '0')
#define chr(x) (((x) == 0) ? '.' : (char)('0' + (x)))

class Solution {
public:
    int mark[9][9];
    set<int> cand[9][9];
    set<pair<int, int>> uns;
    set<pair<int, int>> tts;
    bool cft;

    void print_uns() {
      PR("print uns");
      for (auto& x: uns) {
        PR(x.first);
        PR(x.second);
        for (auto& y: cand[x.first][x.second]) 
          PR(y);
      }
    }

    void scan(vector<vector<char>>& board, pri (Solution::*func)(int,int)) {
      for (int i = 0; i < COM; ++i) {
        vector<int> v;
        for (int j = 0; j < COM; ++j) { 
          auto p = (this->*func)(i, j);
          auto f = p.first, s = p.second;
          if (!is_empty(board[f][s])) 
            v.pb(num(board[f][s]));
        }
        for (int j = 0; j < COM; ++j) {
          auto p = (this->*func)(i, j);
          auto f = p.first, s = p.second;
          if (is_empty(board[f][s])) {
            for (auto it: v)
              cand[f][s].erase(it);
            if (cand[f][s].empty()) { cft = true; return; }
          }
        }
        for (int j = 0; j < COM; ++j) {
          auto p = (this->*func)(i, j);
          auto f = p.first, s = p.second;
          if (is_empty(board[f][s]) && cand[f][s].size() == 1) {
            board[f][s] = chr(*(cand[f][s].begin()));
            tts.insert(p);
            uns.erase(p);
          }
          else if (is_empty(board[f][s])) 
            uns.insert(p);
        }
      }
    }

    pri row_func(int i, int j) {
      return mp(i, j);
    }

    pri column_func(int i, int j) {
      return mp(j, i);
    }

    pri block_func(int i, int j) {
      return mp(i / LCOM * LCOM + j / LCOM, (i % LCOM) * LCOM + j % 3);
    }

    void scan_sudoku(vector<vector<char>>& board) {
        scan(board, &Solution::row_func);
        scan(board, &Solution::column_func);
        scan(board, &Solution::block_func);
    }
  
    void check(vector<vector<char>>& board, pri (Solution::*func)(int,int)) {
      for (int i = 0; i < COM; ++i) {
        set<int> v;
        for (int j = 1; j <= COM; ++j) v.insert(j);
        for (int j = 0; j < COM; ++j) {
          auto p = (this->*func)(i, j);
          auto f = p.first, s = p.second;
          if (!is_empty(board[f][s])) 
            v.erase(num(board[f][s]));
        }
        // check which number occur in only one block
        pri pos[COM + 1];
        int cnt[COM + 1];
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < COM; ++j) {
          auto p = (this->*func)(i, j);
          auto f = p.first, s = p.second;
          if (is_empty(board[f][s])) {
            for (auto& n: cand[f][s]) {
              ++cnt[n];
              pos[n] = p;
            }
          }
        }
        for (auto& n: v) {
          if (cnt[n] == 1) {
            auto f = pos[n].first, s = pos[n].second;
            board[f][s] = chr(n);
            tts.insert(pos[n]);
            uns.erase(pos[n]);
          }
        }
      }
    }

    void check_candidate(vector<vector<char>>& board) {
        check(board, &Solution::row_func);
        check(board, &Solution::column_func);
        check(board, &Solution::block_func);
    }

    void visit_sudoku(vector<vector<char>>& board) {
      int unsz = -1;
      while (unsz != uns.size()) {
        unsz = uns.size();
        scan_sudoku(board);
        if (cft) break;
        check_candidate(board);
      }
    }

    bool finish(vector<vector<char>>& board) {
      for (int i = 0; i < COM; ++i)
        for (int j = 0; j < COM; ++j)
          if (is_empty(board[i][j]))
            return false;
      return true;
    }

    void copy_cand(decltype(cand) cc, decltype(cand) bb) {
      for (int i = 0; i < COM; ++i)
        for (int j = 0; j < COM; ++j)
          cc[i][j] = bb[i][j];
    }

    bool test_dfs(vector<vector<char>>& board) {
       decltype(uns) mm = uns;
       decltype(cand) cc;
       copy_cand(cc, cand);
       for (auto& p: mm) {
         auto f = p.first, s = p.second;
         if (cand[f][s].size() == 2) {
           for (auto& n: cc[f][s]) {
             board[f][s] = chr(n);
             uns.erase(p);
             tts.insert(p);
             visit_sudoku(board);
             if (cft) {
               uns = mm;
               copy_cand(cand, cc);
               cft = false;
               for (auto& x: tts) 
                 board[x.first][x.second] = chr(0);
               tts.clear();
               continue;
             }
             if (finish(board)) { return true; }
             if (test_dfs(board)) { return true; }
             uns = mm;
             copy_cand(cand, cc);
             cft = false;
             for (auto& x: tts) 
               board[x.first][x.second] = chr(0);
             tts.clear();
           }
           break;
         }
       }
       return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        memset(mark, 0, sizeof mark);
        for (int i = 0; i < COM; ++i)
          for (int j = 0; j < COM; ++j)
            for (int k = 1; k <= COM; ++k)
              cand[i][j].insert(k);
        tts.clear();
        uns.clear();
        cft = false;
        visit_sudoku(board);
        if (uns.empty()) return;
        // if not solved, use test method
        test_dfs(board);
    }

};

int main() {
  Solution slt;
  vector<vector<char>> n = {
    {'.','.','.','2','.','.','.','6','3'},{'3','.','.','.','.','5','4','.','1'},{'.','.','1','.','.','3','9','8','.'},{'.','.','.','.','.','.','.','9','.'},{'.','.','.','5','3','8','.','.','.'},{'.','3','.','.','.','.','.','.','.'},{'.','2','6','3','.','.','5','.','.'},{'5','.','3','7','.','.','.','.','8'},{'4','7','.','.','.','1','.','.','.'}
  };
  slt.solveSudoku(n);
  PR("Finally");
  for (auto it: n) {
    PR("x");
    for (auto v: it) {
      PR(v);
    }
  }
  return 0;
}
