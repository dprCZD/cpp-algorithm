#include"common.h"
#include "tree_node.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return dfs(root, 0);
    }
    int dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return depth;
        }
        return max(dfs(root->left, depth + 1), dfs(root->right, depth + 1));
    }
};