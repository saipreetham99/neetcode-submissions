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
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    int length{getLength(head)};
    int index_to_remove{length - n};
    ListNode *cur{head};
    if (!head->next) {
      return nullptr;
    }
    if (length - n == 0) {
      return head->next;
    }
    for (int i{1}; i < length - n; ++i) {
      cur = cur->next;
    }

    cur->next = cur->next->next;
    return head;
  }
  int getLength(ListNode *head) {
    auto cur{head};
    int length{};
    while (cur) {
      ++length;
      cur = cur->next;
    }
    return length;
  }
};