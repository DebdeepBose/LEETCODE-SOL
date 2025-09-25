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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        /*Literally same as level order traversal just reverse the final vector
        thats about it lol*/
        if (root == nullptr) {
            return {};
        }

        vector<vector<int>> bottomLevelOrderValues;
        queue<TreeNode*> nodeQueue;

        nodeQueue.push(root);

        traverseBottomUpLevelOrder(nodeQueue, bottomLevelOrderValues);

        reverse(bottomLevelOrderValues.begin(), bottomLevelOrderValues.end());

        return bottomLevelOrderValues;
    }

    void
    traverseBottomUpLevelOrder(queue<TreeNode*>& nodeQueue,
                               vector<vector<int>>& bottomLevelOrderValues) {

        while (!nodeQueue.empty()) {

            int n = nodeQueue.size();
            vector<int> tempNodes;

            for (int i = 0; i < n; i++) {
                TreeNode* frontNode = nodeQueue.front();
                int frontValue = frontNode->val;
                nodeQueue.pop();

                tempNodes.push_back(frontValue);

                if (frontNode->left != nullptr) {
                    nodeQueue.push(frontNode->left);
                }
                if (frontNode->right != nullptr) {
                    nodeQueue.push(frontNode->right);
                }
            }

            bottomLevelOrderValues.push_back(tempNodes);
        }
    }
};