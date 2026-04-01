class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> ch;
        int n = s.size();
        int i =0;
        int maxlength = 0;
        for(int j = 0;j<n;j++){
            while(ch.find(s[j]) != ch.end()){
                ch.erase(s[i]);
                i++;
            }
            ch.insert(s[j]);
            maxlength = max(maxlength,j - i + 1);
        }
        return maxlength;
    }
};