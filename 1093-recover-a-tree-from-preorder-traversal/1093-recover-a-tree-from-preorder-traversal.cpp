/**
 * Definition for a binary tree node.
 */
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
// };

class Solution {
public:
    TreeNode* recoverFromPreorder(string t) {
        int n = t.size();
        vector<TreeNode*> list(10001, nullptr);
        int rootVal = 0, i = 0;


        while(i < n && t[i] != '-') {
            rootVal = rootVal * 10 + (t[i] - '0');
            i++;
        }
        list[0] = new TreeNode(rootVal);

        while(i < n) {
            int depth = 0;
          
            while(i < n && t[i] == '-') {
                depth++;
                i++;
            }

            int nodeVal = 0;
    
            while(i < n && t[i] != '-') {
                nodeVal = nodeVal * 10 + (t[i] - '0');
                i++;
            }

            TreeNode* child = new TreeNode(nodeVal);
            TreeNode* parent = list[depth - 1];

            if(!parent->left)
                parent->left = child;
            else
                parent->right = child;

            list[depth] = child;
        }

        return list[0];
    }
};
