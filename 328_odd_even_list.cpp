#include "common.h"
#include "list_node.h"
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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr||head->next == nullptr) {
            return head;
        }
        ListNode* oddHead = new ListNode();
        ListNode* evenHead = new ListNode();
        ListNode* oddCur = oddHead;
        ListNode* evenCur = evenHead;
        ListNode* cur = head;
        int i = 1;
        while (cur != nullptr) {
            if (i % 2 == 1) {
                oddCur->next = cur;
                oddCur = oddCur->next;
            }
            else {
                evenCur->next = cur;
                evenCur = evenCur->next; 
            }
            cur = cur->next;
            ++i;
        }
        oddCur->next = evenHead->next;
        evenCur->next = nullptr;
        return oddHead->next;
    }
};