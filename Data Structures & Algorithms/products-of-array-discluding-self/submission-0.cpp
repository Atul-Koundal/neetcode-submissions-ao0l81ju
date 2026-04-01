class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
 int n = nums.size();
        int product = 1;
        int zeroCount = 0;
        for(int i = 0;i<n;i++){
            if(nums[i] == 0){
                zeroCount++;
            }else{product*=nums[i];
            }
        }

         vector<int> result(n, 0);
         if(zeroCount > 1){
            return result;
         }
        for(int i =0;i<n;i++){
            if(zeroCount == 0){
            result[i] = product/nums[i];
            }else if(nums[i] == 0){
                result[i] = product;
            }
        }
        return result;
    }
};
