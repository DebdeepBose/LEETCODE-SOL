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
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*Alright this one, look its easy just follow this
        We take a Queue for this and such questions where level order traversla
        is required so ingrain it into your brayyyn, now simpley follow this

        We push root into queue, then jump inside a while loop
        That loop goes on until Queue is not empty
        Basically what we do is, we take the size of the queue, and
        an empty vector to store temporary values.
        Next for the size of the queue we iterate, aka traverse the queue
        with a simple for loop.
        Now for each element in the queue we repeat this:
            Store the front -> pop the front, push stored front into temp Vector
            If frontNode -> left isnt nullptr, push it into queue.
            If frontNode -> right isnt nullptr, push it into queue.
        After loop ends push temp Vector into Ans

        This got messy so imma call a function for this purpose but u can
        do it here itself
        */

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        vector<vector<int>> levelOrderValues;

        levelOrderTraversal(root, nodeQueue, levelOrderValues);

        return levelOrderValues;
    }

    void levelOrderTraversal(TreeNode* currentNode, queue<TreeNode*>& nodeQueue,
                             vector<vector<int>>& levelOrderValues) {

        // Ok so if the root we passed turns out to be null well then gg return
        if (currentNode == nullptr) {
            return;
        }

        while (!nodeQueue.empty()) {

            // We initialize size and temp vector
            // Yeah outside or else for every element in the queue
            // a new temp vector would be initialize
            int queueSize = nodeQueue.size();
            vector<int> temporaryNodeValues;

            for (int i = 0; i < queueSize; i++) {

                // These 3 lines basically take out the front Node and store its
                // value
                TreeNode* frontNode = nodeQueue.front();
                nodeQueue.pop();
                int frontNodeValue = frontNode->val;

                // Gotta stored that popped node
                temporaryNodeValues.push_back(frontNodeValue);

                // Now we check if left/right valid or no
                if (frontNode->left != nullptr) {
                    nodeQueue.push(frontNode->left);
                }

                if (frontNode->right != nullptr) {
                    nodeQueue.push(frontNode->right);
                }
            }

            // WE POOSH
            levelOrderValues.push_back(temporaryNodeValues);
        }
    }
};