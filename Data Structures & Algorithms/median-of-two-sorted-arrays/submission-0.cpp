class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n = nums1.size();
        int m = nums2.size();
        vector<int> vec;
        for(int i =0;i<n;i++){
            vec.push_back(nums1[i]);
        }
        for(int i =0;i<m;i++){
            vec.push_back(nums2[i]);
        }
        sort(vec.begin(),vec.end());
        int size = vec.size();
        if(size%2 == 0){
             return (vec[size / 2 - 1] + vec[size / 2]) / 2.0;
        }else{
            return vec[size/2];
        } 
    }
};
