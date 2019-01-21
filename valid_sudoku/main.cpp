#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <tuple>
#include <utility>
#include <set>
#include <cstring>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define PR(x) cout << #x << ": " << (x) << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: (x)) cout << it << ' '; cout << endl;
#define COM 9

class Solution {
public:
    bool isRowValid(vector<vector<char>>& board) {
      int cnt[COM + 1];
      for (int i = 0; i < COM; ++i) {
        memset(cnt, 0, sizeof cnt);
        for (int j = 0; j < COM; ++j) {
          if (board[i][j] != 0 && cnt[board[i][j]] == 1) return false;
          ++cnt[board[i][j]];
        }
      }
      return true;
    }

    bool isColumnValid(vector<vector<char>>& board) {
      int cnt[COM + 1];
      for (int j = 0; j < COM; ++j) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < COM; ++i) {
          if (board[i][j] != 0 && cnt[board[i][j]] == 1) return false;
          ++cnt[board[i][j]];
        }
      }
      return true;
    }

    bool isBoardValid(vector<vector<char>>& board) {
      int cnt[COM + 1];
      for (int i = 0; i < COM; ++i) {
        int rst = (i / 3) * 3;
        int red = rst + 3;
        int lst = (i % 3) * 3;
        int led = lst + 3;
        memset(cnt, 0, sizeof cnt);
        for (int j = rst; j < red; ++j) {
          for (int k = lst; k < led; ++k) {
            if (board[j][k] != 0 && cnt[board[j][k]] == 1) return false;
            ++cnt[board[j][k]];
          }
        }
      }
      return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
      // preprocessing
      for (int i = 0; i < COM; ++i) 
        for (int j = 0; j < COM; ++j) {
          if (board[i][j] == '.') board[i][j] = 0;
          else board[i][j] -= '0';
        }
      // see row 
      if (isRowValid(board) && isColumnValid(board) && isBoardValid(board)) return true;
      return false;
    }
};

int main() {
  vector<vector<char>> board = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  Solution slt;
  PR(slt.isValidSudoku(board));
  return 0;
}
