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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root->left,root->right);
        TreeNode* ptrl = root->left;
        while(ptrl){
        swap(ptrl->left,ptrl->right);
        ptrl = ptrl->left;
        }
        TreeNode* ptrr = root->right;
        while(ptrr){
        swap(ptrr->left,ptrr->right);
        ptrr = ptrr->right;
        }
        
        return root;
    }
};
