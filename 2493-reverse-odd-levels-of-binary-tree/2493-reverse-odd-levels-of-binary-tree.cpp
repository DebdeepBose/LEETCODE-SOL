class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) {
            return nullptr;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<TreeNode*> tmp;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node);

                if (node->left) {
                    q.push(node->left);
                }

                if (node->right) {
                    q.push(node->right);
                }
            }

            if (level % 2 == 1) {
                int i = 0, j = tmp.size() - 1;
                while (i < j) {
                    swap(tmp[i]->val, tmp[j]->val);
                    i++;
                    j--;
                }
            }

            level++;
        }

        return root;
    }
};
