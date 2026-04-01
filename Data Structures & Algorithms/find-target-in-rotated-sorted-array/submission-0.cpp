class Solution {
public:
         int findPivot(vector<int> &nums){
        int s = 0;
        int e = nums.size() - 1;
       if (nums[s] <= nums[e]) return 0; 
        while(s<e){
            int mid = s+(e-s)/2;
            if(nums[mid] < nums[0]){
                    e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
            }

int binarySearch(vector<int>& nums, int target,int s ,int e){
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid]<target){
                s = mid+1;
            }
            else{
                e = mid -1;
            }
            mid = s+(e-s)/2;

        }
        return -1;
}
int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        if(pivot == 0 || target < nums[0]){
            return binarySearch(nums,target,pivot,nums.size() - 1);
        }
        else{
             return binarySearch(nums,target,0,pivot - 1);
        }


    }
};
