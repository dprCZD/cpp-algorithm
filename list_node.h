#pragma once
#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

    static ListNode* createList(vector<int>nodes) {
        if (nodes.size() == 0) {
            return nullptr;
        }
        ListNode* head = new ListNode(nodes[0]);
        ListNode* cur =head;
        for (int i = 1; i < nodes.size(); ++i) {
            cur->next = new ListNode(nodes[i]);
            cur = cur->next;
        }
        return head;
    }
};
 