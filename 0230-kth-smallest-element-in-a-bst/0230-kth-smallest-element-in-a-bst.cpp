/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        find(pq, root, k);
        return pq.top();
    }
    void find(priority_queue<int>& pq, TreeNode* node, int k) {
        if (!node) {
            return;
        }
        if (node) {
            pq.push(node->val);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        find(pq, node->left, k);
        find(pq, node->right, k);
    }
};