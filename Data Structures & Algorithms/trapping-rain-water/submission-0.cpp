class Solution {
public:
vector<int> getLeftMax(const vector<int>& height, int n){
       vector<int> leftMax(n);
       leftMax[0] = height[0];
        for(int j =1;j<n;j++){
           leftMax[j] = max(leftMax[j-1],height[j]);
        }
        return leftMax;
}
  vector<int> getRightMax(const vector<int>& height, int n){
        vector<int> rightMax(n);
       rightMax[n-1] = height[n-1];
        for(int j =n-2;j>=0;j--){
           rightMax[j] = max(rightMax[j+1],height[j]);
        }
        return rightMax;
}

int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        vector<int> leftMax = getLeftMax(height,n);
        vector<int> rightMax = getRightMax(height,n);
        for(int i =0;i<n;i++){
            int h = min(leftMax[i],rightMax[i]) - height[i];
            sum +=h;
        }
        return sum;
    }
};