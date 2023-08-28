#include "common.h"
#include "tree_node.h"



class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        deque<TreeNode*> queue;
        queue.push_back(root);
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<int> levelNodes;
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* cur = queue.front();
                queue.pop_front();
                levelNodes.push_back(cur->val);
                if (cur->left) {
                    queue.push_back(cur->left);
                }
                if (cur->right) {
                    queue.push_back(cur->right);
                }
            }
            res.push_back(levelNodes);
        }
        return res;
    }
};