class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>freq;

        for(int num : nums){
            freq[num]++;
        }

        vector<pair<int,int>>freqVec;
        for(auto &it:freq){
            freqVec.push_back({it.second,it.first});
        }

        sort(freqVec.rbegin(),freqVec.rend());
         vector<int>result;
        for(int i = 0;i<k;i++){
            result.push_back(freqVec[i].second);
        }
        return result;
    }
};
