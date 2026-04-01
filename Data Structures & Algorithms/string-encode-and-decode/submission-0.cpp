class Solution {
  public:
    string encode(vector<string>& s) {
        // code here
        string result;
        for(string &str : s){
            result+=(to_string(str.size()) + "#" + str);
         
        }
           return result;
    }

    vector<string> decode(string& s) {
        
        // code here
        vector<string> result;
        int i = 0;
        while(i<s.size()){
            int j =i;
            while(s[j] != '#') j++;
            
            int length = stoi(s.substr(i,j - i));
            string word = s.substr(j + 1,length);
            result.push_back(word);
            i = j+1+length;
        }
        return result;
    }
};