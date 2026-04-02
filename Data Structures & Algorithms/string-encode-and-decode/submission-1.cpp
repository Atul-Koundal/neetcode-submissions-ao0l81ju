class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(string &str : strs){
            result+=to_string(str.lrngth()) + "#" + str;
        }
        return str;
    }

    vector<string> decode(string s) {
        int n = s.length();
        vector<string>result;
        int i =0;
        while(i<n){
            int j =  i + 1;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i,j - 1));
            string word = s.substr(j+1,length);
            result.push_back(word);
        }
        return result;
    }
};
