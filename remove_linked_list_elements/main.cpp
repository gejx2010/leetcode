#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
      while (head != NULL && head->val == val) head = head->next;
      if (head == NULL) return head;
      ListNode *x = head, *y = head->next;
      while (y != NULL) {
        if (y->val == val) {
          x->next = y->next;
          y = y->next;
        } else {
          x = y;
          y = y->next;
        }
      }
      return head;
    }

};

int main() {
  vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  Solution slt;
  cout << slt.maxSubArray(n) << endl;
  return 0;
}
