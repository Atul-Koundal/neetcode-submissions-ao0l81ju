class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n + 1,0);
        for(int i =0;i<=n;i++){
            int x = i;
            int count = 0;
            while(x){
                count += x & 1;
                x >>= 1;
            }
            ans[i] = count;
        }
        return ans;
    }
};