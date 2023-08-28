#include "tree_node.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return root;
        }
        //ƥ�䵽p q
        if (root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        //������Ҷ���Ϊ�գ�˵����ǰ�ڵ��ǹ������ȡ�
        if (left != nullptr && right != nullptr) {
            return root;
        }
        //�����ڵ㲻Ϊ�գ�˵����ڵ����pq�����ǹ������ȡ�
        if (left != nullptr) {
            return left;
        }
        //����ҽڵ㲻Ϊ�գ�˵���ҽڵ����pq�����ǹ������ȡ�
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }
};