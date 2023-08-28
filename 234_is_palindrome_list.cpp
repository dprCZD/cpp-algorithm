#include "list_node.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* midHead = reverse(slow->next);
        slow->next = nullptr;
        while (midHead != nullptr) {
            if (head->val != midHead->val) {
                return false;
            }
            midHead = midHead->next;
            head = head->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        if (head == nullptr||head->next ==nullptr) {
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