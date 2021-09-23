class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxSum = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            maxSum = max(maxSum + nums[i], nums[i]);
            ans = max(maxSum, ans);
        }
        return ans;
    }
};