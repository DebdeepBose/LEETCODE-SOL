class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        replaceNodes(root, target);
        if (root && isLeaf(root) && root->val == target) {
            return nullptr;
        }
        return root;
    }

    void replaceNodes(TreeNode* node, int target) {
        if (!node) {
            return;
        }

        replaceNodes(node->left, target);
        replaceNodes(node->right, target);

        if (node->left && node->left->val == target && isLeaf(node->left)) {
            node->left = nullptr;
        }
        if (node->right && node->right->val == target && isLeaf(node->right)) {
            node->right = nullptr;
        }
    }

    bool isLeaf(TreeNode* node) {
        return node && !node->left && !node->right;
    }
};
