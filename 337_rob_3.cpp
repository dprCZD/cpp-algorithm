#include "common.h"
#include "tree_node.h"

struct Status {
    int selected;
    int notSelected;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        Status left = dfs(root->left);
        Status right = dfs(root->right);
        int selected = root->val + left.notSelected + right.notSelected;
        int notSelected = max(left.selected, left.notSelected) + max(right.selected, right.notSelected);
        return { selected,notSelected };
    }
    int rob(TreeNode* root) {
        Status res = dfs(root);
        return max(res.selected, res.notSelected);
    }
};