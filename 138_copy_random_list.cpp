#include "random_list_node.h"
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> cachedNodes;

    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        if (!cachedNodes.count(head)) {
            Node* newNode = new Node(head->val);
            cachedNodes[head] = newNode;
            newNode->next = copyRandomList(head->next);
            newNode->random = copyRandomList(head->random);
        }
        return cachedNodes[head];

    }

    Node* copyRandomList2(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        for (Node* node = head; node != NULL; node = node->next->next) {
            Node* newNode = new Node(node->val);
            newNode->next = node->next;
            node->next = newNode;
        }
        for (Node* node = head; node != NULL; node = node->next->next) {
            Node* newNode = node->next;
            newNode->random = node->random == NULL ? NULL : node->random->next;
        }
        Node* newHead = head->next;
        for (Node* node = head; node != NULL; node = node->next) {
            Node* newNode = node->next;
            node->next = node->next->next;
            newNode->next = newNode->next == NULL ? NULL : newNode->next->next;
        }        
        return newHead;

    }

};