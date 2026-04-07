class Solution {
public:
    int reverse(int x) {
        int reversenum = 0;
        while(x !=0){
            int remender = x%10;
            if(reversenum>INT_MAX/10 ||reversenum<INT_MIN/10){
                return 0;
            }
            reversenum = reversenum * 10 + remender;
            x/=10;
        }
        return reversenum;
    }
};