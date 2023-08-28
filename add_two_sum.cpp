#include "common.h"
#include "list_node.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode();
        ListNode* cur = preHead;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int num1 = l1 == nullptr ? 0 : l1->val;
            int num2 = l2 == nullptr ? 0 : l2->val;
            int sum = num1 + num2 + carry;
            if (sum > 9) {
                sum %= 10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            cur->next = new ListNode(sum);
            cur = cur->next;
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }
        if (carry == 1) {
            cur->next = new ListNode(1);
        }
        //>destory
        ListNode* res = preHead->next;
        delete preHead;
        return res;
    }
};