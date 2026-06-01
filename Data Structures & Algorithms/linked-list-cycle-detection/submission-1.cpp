/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
    auto cur{head};
    auto ahead{head};
    while (cur) {
      if ((!ahead->next) || (!ahead->next->next))
        return false;
      if (ahead->next == cur || ahead->next->next == cur) {
        return true;
      }
      cur = cur->next;
      ahead = ahead->next->next;
    }
    return false;
  }
};
