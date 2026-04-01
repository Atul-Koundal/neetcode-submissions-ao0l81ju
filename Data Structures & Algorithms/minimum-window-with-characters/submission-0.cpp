class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0, j = 0;
        int minLen = INT_MAX, start = 0;
        
        vector<int> count(128, 0); 
        for (char c : t) {
            count[c]++;
        }

        while (i < n) {
            if (count[s[i]] > 0) {
                m--;
            }
            count[s[i]]--;
            i++;

            while (m == 0) {
                if (i - j < minLen) {
                    minLen = i - j;
                    start = j;
                }

                count[s[j]]++;
                if (count[s[j]] > 0) {
                    m++;
                }
                j++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};
