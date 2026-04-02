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
    int sum = 0;
    int maxSum(TreeNode* curr){
        if(!curr) return 0;

            int left = max(0,maxSum(curr->left));
            int right = max(0,maxSum(curr->right));

            sum = max(sum,curr->val+left+right);

            return sum;
        
    }
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return sum;
    }
};
