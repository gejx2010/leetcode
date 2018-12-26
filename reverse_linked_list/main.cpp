#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define PR(x) cout << #x << ": " << x << endl;
#define PRV(x) cout << #x << ": "; for (auto& it: x) cout << it << ' '; cout << endl;
#define PRL(x) cout << #x << ": "; while (x) { cout << (x)->val << ' '; (x) = (x)->next; } cout << endl;


struct ListNode {
 int val;
  ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if (head == NULL || head->next == NULL) return head; 
       ListNode *cn = NULL, *bn = head, *an = head->next;
       while (an != NULL) {
         bn->next = cn;
         cn = bn;
         bn = an;
         an = an->next;
       }
       bn->next = cn;
       return bn;
    }
};

int main() {
  ListNode a(5), b(1), c(4), d(7), e(2);
  a.next = &b, b.next = &c, c.next = &d, d.next = &e;
  Solution slt;
  ListNode* res = slt.reverseList(&a);
  PRL(res);
  return 0;
}
