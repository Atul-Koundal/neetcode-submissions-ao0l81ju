class Solution {
public:
    vector<vector<int>> ans;
    vector<int>path;
    void backtrack(int start,int sum,vector<int>candidates,int target){
        if(sum == target){
            ans.push_back(path);
            return;
        }
        if(sum > target){
            return;
        }
        for(int i = start;i<candidates.size();i++){
            if(i>start && candidates[i] == candidates[i - 1]) continue;

            path.push_back(candidates[i]);
            backtrack(i+1,sum+candidates[i],candidates,target);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(0,0,candidates,target);
        return ans;
    }
};