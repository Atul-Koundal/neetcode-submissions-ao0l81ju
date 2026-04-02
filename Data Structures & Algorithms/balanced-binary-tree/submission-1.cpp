/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int diff;
    int height(TreeNode* curr){
        if(!curr) return 0;
        int left = height(curr->left);
        int right = height(curr->right);

        diff = max(diff,left - right);
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        diff = 0;
        height(root);
        if(diff>1 || diff< -1){
            return false;
        }
        return true;
    }
};
