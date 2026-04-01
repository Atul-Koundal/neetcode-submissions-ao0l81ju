class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result;
        for(int i =0;i<n;i++){
            int j = i+1;
            int count = 1;
            while(j<n && temperatures[j] <= temperatures[i]){
                count++;
                j++;
                
            }if(j == n){
                    result.push_back(0);
                }else{
            result.push_back(count);
                }
        }
       return result;
    }
};
