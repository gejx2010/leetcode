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
    ListNode* deleteDuplicates(ListNode* head) {
       if (head == NULL) return head;
       ListNode *cur = head, *nt = head->next;
       while (nt != NULL) {
         if (cur->val != nt->val) {
           cur->next = nt;
           cur = nt;
         }
         nt = nt->next;
       }
       cur->next = NULL;
       return head;
    }
};

int main() {
  vector<int> n = {-2,1,-3,4,-1,2,1,-5,4};
  Solution slt;
  cout << slt.maxSubArray(n) << endl;
  return 0;
}
