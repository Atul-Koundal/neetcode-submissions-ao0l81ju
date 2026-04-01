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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode();
        if(preorder.empty() || inorder.empty()) return nullptr;
        root->val =preorder[0];
        preorder.erase(preorder.begin());
        int size = inorder.size();
        vector<int>left;
        vector<int>right;
        int rootIndex;
        for(int i = 0;i<size;i++){
            if(inorder[i] == root->val){
                rootIndex = i;
            }
        }
        for(int i =0;i<rootIndex;i++){
            left.push_back(inorder[i]);
        }
        for(int i = rootIndex + 1;i<size;i++){
            right.push_back(inorder[i]);
        }
    root->left = buildTree(preorder,left);
    root->right = buildTree(preorder,right);
    return root;
    }
};
