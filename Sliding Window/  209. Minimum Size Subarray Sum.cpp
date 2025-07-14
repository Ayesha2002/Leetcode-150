
//Time complexity:O(n)
//Space complexity:O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n= nums.size();
        int l=0,r=0;
        int minLength= INT_MAX;
        int sum=0;

        while(r<n){
            sum +=nums[r];
            //decrease the window size
            while(sum>=target){
                minLength= min(minLength, r-l+1);
                sum -=nums[l];
                l++;
            }
            r++;
        }
        return minLength == INT_MAX ? 0:minLength;
    }
};
