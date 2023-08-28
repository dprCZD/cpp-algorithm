#include "common.h"
#include "tree_node.h"
class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int length = preorder.size();
        for (int i = 0; i < length; ++i) {
            index[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, length - 1, 0, length - 1);

    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preLeft, int preRight, int inLeft, int inRight) {
        if (preLeft < preRight) {
            return nullptr;
        }
        // 前序遍历中的第一个节点就是根节点
        int rootIndex = index[preorder[preLeft]];

        // 在中序遍历中定位根节点
        TreeNode* root = new TreeNode(inorder[rootIndex]);

        // 得到左子树中的节点数目
        int leftNum = rootIndex - inLeft;

        root->left = build(preorder, inorder, preLeft + 1, preLeft + leftNum, inLeft, rootIndex - 1);
        root->right = build(preorder, inorder, preLeft + leftNum + 1,preRight, rootIndex + 1, inRight);
        return root;
    }
};