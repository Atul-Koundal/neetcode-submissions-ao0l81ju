/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        TreeNode* ptr =  root;
        if((ptr->val >= p->val && ptr->val<=q->val) ||(ptr->val <= p->val && ptr->val>=q->val)){
            return ptr;
        }
        else if((ptr->val > p->val) && (ptr->val > q->val)){
            return lowestCommonAncestor(ptr->left,p,q);
        }else{
            return lowestCommonAncestor(ptr->right,p,q);
        }
    }
};