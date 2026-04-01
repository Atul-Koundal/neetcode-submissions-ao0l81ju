class Solution {
public:
    bool isPalindrome(string s){
        int i =0,j = s.size() - 1;
            while(i<j){
                if(s[i] != s[j]) return false;
                i++;
                j--;
            }
         return true;
    }

    void backtrack(int idx,string &s,vector<vector<string>>&res,vector<string>&curr){
        if(idx == s.size()){
            res.push_back(curr);
            return;
        }
        string temp = "";
        for(int i = idx;i < s.size();i++){
            temp+=s[i];
            if(isPalindrome(temp)){
            curr.push_back(temp);
            backtrack(i+ 1,s,res,curr);
            curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;
        backtrack(0,s,res,curr);
        return res;
    }
};