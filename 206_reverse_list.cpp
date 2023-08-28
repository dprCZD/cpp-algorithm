#include"list_node.h"


/**
* 206. Reverse Linked List
* Given the head of a singly linked list, reverse the list, and return the reversed list.
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        head->next = nullptr;
        return pre;

    }
};