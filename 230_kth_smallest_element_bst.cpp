#include "tree_node.h"


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while (cur != nullptr || !stack.empty()) {
            while (cur != nullptr) {
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            --k;
            if (k == 0) {
                return cur->val;
            }
            cur = cur->right;
        }
        return -1;
    }
};