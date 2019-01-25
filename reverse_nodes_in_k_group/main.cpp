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

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
   ListNode(vector<int> v) {
     ListNode *bf = this, *cr = bf;
     for (int i = 0; i < v.size(); ++i) {
       if (cr == bf) {
         cr->val = v[i];
         if (bf->next == nullptr && i < v.size() - 1)
           bf->next = new ListNode(0);
         cr = bf->next;
       } else {
         cr->val = v[i];
         if (cr->next == nullptr && i < v.size() - 1) cr->next = new ListNode(0);
         cr = cr->next;
       }
     }
   }

   void print() {
     PR("print list nodes.");
     ListNode* p = this;
     while (p) {
       PR(p->val);
       p = p->next;
     }
   }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (k <= 1) return head;
      if (head == nullptr || head->next == nullptr) return head;
      ListNode *s = head, *e = head, *l = head;
      ListNode *r = l->next;
      ListNode *n;
      int cnt = 2;
      while (r != nullptr) {
        n = r->next;
        if (cnt < k) {
          r = r->next;
          ++cnt;
        } else {
          ListNode* m = l->next;
          ListNode* mn = m->next;
          while (m != r) {
            m->next = l;
            l = m;
            m = mn;
            mn = mn->next;
          }
          r->next = l;
          l = r;
          r = n;
          if (s == head) head = l;
          else s->next = l;
          e->next = r;
          s = e;
          e = r;
          l = r;
          cnt = 2;
          if (r != nullptr) r = r->next;
        }
      }
      return head;
    }
};

int main() {
  Solution slt;
  vector<int> n = {1, 2, 3, 4, 5, 6, 7, 8};
  ListNode* h = new ListNode(n);
  h->print();
  int k = 5;
  h = slt.reverseKGroup(h, k);
  h->print();
  return 0;
}
