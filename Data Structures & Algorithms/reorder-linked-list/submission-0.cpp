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
  ListNode *getMiddle(ListNode *head) {
    auto slow{head};
    auto fast{head};
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  void reorderList(ListNode *head) {
    ListNode new_head{};
    auto middle = getMiddle(head);
    auto second{middle->next};
    middle->next = nullptr;
    auto first = head;
    second = reverseList(second);
    while (second) {
      auto tmp1 = first->next;
      auto tmp2 = second->next;
      first->next = second;
      second->next = tmp1;
      first = tmp1;
      second = tmp2;
    }
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev{};
    auto cur = head;
    while (cur) {
      auto next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    return prev;
  }
};