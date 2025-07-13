//Time complexity:O(n^2)
//Space complexity:O(1)


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } 
                else if (sum > 0) {
                    k--;
                } 
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (nums[k] == nums[k + 1] && k > j) k--;
                    while (nums[j] == nums[j - 1] && j < k) j++;
                }
            }
        }
        return ans;
    }
};
