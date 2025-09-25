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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        /*Yes this is more so an easy question all u gotta do is level order
         * traversal but just take a boolean flag as true and flip it when u
         * going to store ans, if the flag is false , our temporary vector will
         * reverse itslef otherwise things will go on, super easy */

        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> nodeQueue;
        vector<vector<int>> ZigZagNodeList;
        bool ZigZag = true;

        nodeQueue.push(root);
        zigzagTraversal(nodeQueue, ZigZag, ZigZagNodeList);

        return ZigZagNodeList;
    }

    // I mean the queue already has the root so no use of taking it again

    void zigzagTraversal(queue<TreeNode*>& nodeQueue, bool ZigZag,
                         vector<vector<int>>& ZigZagNodeList) {
        while (!nodeQueue.empty()) {
            int n = nodeQueue.size();
            vector<int> tempNodeList;

            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = nodeQueue.front();
                nodeQueue.pop();

                tempNodeList.push_back(frontNode->val);

                if (frontNode->left != nullptr) {
                    nodeQueue.push(frontNode->left);
                }
                if (frontNode->right != nullptr) {
                    nodeQueue.push(frontNode->right);
                }
            }

            if (!ZigZag) {
                reverse(tempNodeList.begin(), tempNodeList.end());
            }
            ZigZagNodeList.push_back(tempNodeList);
            ZigZag = !ZigZag;
        }
    }
};
