class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    vector<bool>isTarget;
    void backtrack(int i,int sum,vector<int>&nums,int target){
       if(sum == target){
        ans.push_back(path);
        return;
       }
       if(sum>target || i == nums.size()){
        return;
       }
       path.push_back(nums[i]);
       backtrack(i,sum+nums[i],nums,target);
       path.pop_back();

       backtrack(i+1,sum,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0,0,nums,target);
        return ans;
    }
};
