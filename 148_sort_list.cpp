#include "common.h"
#include "list_node.h"

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // ¹é²¢
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left == NULL ? right : left;
        return res->next;
    }


    // ¹é²¢
    ListNode* merge(ListNode* start, ListNode* end, int size) {
        if (start == end) {
            return start;
        }
        int midIdx = size / 2;
        ListNode* mid = start;
        for (int i = 0; i < midIdx-1; ++i) {
            mid = mid->next;
        }

        ListNode* left = merge(start, mid,midIdx);
        ListNode* right = merge(mid->next, end, size % 2 == 0 ? midIdx : midIdx + 1);
       
        ListNode* merged = nullptr;
        if (left->val < right->val) {
            merged = left;
            left = left->next;
        }
        else {
            merged = right;
            right = right->next;
        }
        ListNode* cur = merged;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                cur->next = left;
                left = left->next;
            }
            else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;

        }
        cur->next = left == nullptr ? right : left;
        return merged;
    }


};

//int main() {
//    Solution su;
//    su.sortList(ListNode::createList({ 4,2,1,3 }));
//}