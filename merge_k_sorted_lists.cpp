#include "common.h"
#include"list_node.h"
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        return merge(lists, 0, lists.size() - 1);   
    }
    ListNode* merge(vector<ListNode*>& lists,int lIdx, int rIdx) {
        if (lIdx == rIdx) {
            return lists[lIdx];
        }
        int midIdx = (lIdx + rIdx) / 2;
        ListNode* left = merge(lists, lIdx, midIdx);
        ListNode* right = merge(lists, midIdx+1, rIdx);
        return mergeLists(left, right);
    }

    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode sentinel;
        ListNode* cur = &sentinel;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == nullptr ? l2 : l1;
        return sentinel.next;
    }
};