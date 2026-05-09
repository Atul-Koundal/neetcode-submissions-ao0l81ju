class Solution {
public:
    void dfs(TreeNode* root,vector<int> &result){
        if(!root) return;

        dfs(root->left,result);
        result.push_back(root->val);
        dfs(root->right,result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        dfs(root,result);
        return result;
    }
};