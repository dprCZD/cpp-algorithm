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
        // ǰ������еĵ�һ���ڵ���Ǹ��ڵ�
        int rootIndex = index[preorder[preLeft]];

        // ����������ж�λ���ڵ�
        TreeNode* root = new TreeNode(inorder[rootIndex]);

        // �õ��������еĽڵ���Ŀ
        int leftNum = rootIndex - inLeft;

        root->left = build(preorder, inorder, preLeft + 1, preLeft + leftNum, inLeft, rootIndex - 1);
        root->right = build(preorder, inorder, preLeft + leftNum + 1,preRight, rootIndex + 1, inRight);
        return root;
    }
};