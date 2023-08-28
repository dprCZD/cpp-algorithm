#include "tree_node.h"
#include "common.h"
class Solution {
public:

    int rootSum(TreeNode* root, int64_t targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        if (targetSum == root->val) {
            ++ret;
        }
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;

    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int ret = rootSum(root,targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;

    }

    unordered_map<int64_t, int> prefix;

    int dfs(TreeNode* root, long long cur, int targetSum) {
        if (root == nullptr) {
            return 0;
        }
        int ret = 0;
        cur += root->val;
        if (prefix.count(cur - targetSum)) {
            ret = prefix[cur - targetSum];
        }
        prefix[cur]++;
        ret += dfs(root->left, cur, targetSum);
        ret += dfs(root->right, cur, targetSum);
        prefix[cur]--;
        return ret;
    }

    int pathSum2(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root,0,targetSum);

    }
};