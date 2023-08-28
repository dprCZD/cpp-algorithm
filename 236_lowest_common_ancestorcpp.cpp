#include "tree_node.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        //匹配到p q
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //如果左右都不为空，说明当前节点是公共祖先。
        if (left != nullptr && right != nullptr) {
            return root;
        }
        //如果左节点不为空，说明左节点包含pq或者是公共祖先。
        if (left != nullptr) {
            return left;
        }
        //如果右节点不为空，说明右节点包含pq或者是公共祖先。
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }
};