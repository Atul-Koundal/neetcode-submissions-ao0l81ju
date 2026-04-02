class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        unordered_map<int, int> mp;
        for(int i = 0;i <n;i++){
            int count = 0;
            while(position[i] < target){
                position[i] += speed[i];
                count++;
            }
           mp[count]++; 
        }
        int fleets = mp.size();
return fleets;
}
    };
