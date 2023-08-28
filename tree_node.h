#pragma once
#include "common.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    static TreeNode* createTree(vector<std::string> nodes, int i = 0) {
        if (i>=nodes.size()||nodes[i] == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(atoi(nodes[i].c_str()));
        root->left = createTree(nodes, 2 * i + 1);
        root->right = createTree(nodes, 2 * i + 2);
        return root;
    }
};



 