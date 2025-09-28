class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int k) {
        if (!root) {
            return new TreeNode(k); 
        }
        insert(root, k);
        return root;
    }

    void insert(TreeNode* node, int k) {
        if (!node) {
            return;
        }

        if (k < node->val) {
            if (!node->left) {
                node->left = new TreeNode(k);
                return;
            }
            insert(node->left, k);
        } else if (k > node->val) {
            if (!node->right) {
                node->right = new TreeNode(k);
                return;
            }
            insert(node->right, k);
        }
    }
};
