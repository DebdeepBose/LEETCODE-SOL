class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq; 
        find(root, pq, k);
        return pq.top();
    }

    void find(TreeNode* node, priority_queue<int>& pq, int k) {
        if (!node) {
            return;
        }

        pq.push(node->val);
        if (pq.size() > k) {
            pq.pop();
        }

        find(node->left, pq, k);
        find(node->right, pq, k);
    }
};
