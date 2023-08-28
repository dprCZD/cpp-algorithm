#include "common.h"
#include "tree_node.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        iter(root, res);
        return res;

    }
    void dfs(TreeNode* root, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right, res);
    }
    void iter(TreeNode* root, vector<int>& res) {
        stack<TreeNode*> s;
        while (root!=nullptr||!s.empty()) {
            while (root != nullptr) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }

    }
};