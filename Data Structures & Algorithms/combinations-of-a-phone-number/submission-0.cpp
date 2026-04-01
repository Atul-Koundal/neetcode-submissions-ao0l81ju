class Solution {
public:
unordered_map<char,string> mp = {
    {'2',"abc"},
    {'3',"def"},
    {'4',"ghi"},
    {'5',"jkl"},
    {'6',"mno"},
    {'7',"pqrs"},
    {'8',"tuv"},
    {'9',"wxyz"}
};
    vector<string>res;
    void backtrack(int idx,string &digits,string temp){
        if(idx == digits.size()){
            res.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i = 0;i<str.size();i++){
            temp.push_back(str[i]);
            backtrack(idx + 1,digits,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0){
            return {};
        }
        string temp = "";
        backtrack(0,digits,temp);
        return res;
    }
};