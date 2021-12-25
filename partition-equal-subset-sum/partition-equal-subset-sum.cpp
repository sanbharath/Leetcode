class Solution {
public:
    vector<vector<int>> t;
    bool subsetSumFind(vector<int>& nums, int sum, int n) {
        if(t[n][sum] != -1)
            return t[n][sum];
        if(sum == 0) {
            return t[n][sum] = true;
        }
        if(n == 0) {
            return t[n][sum] = false;
        }
        
        if(nums[n-1] <= sum)
            return t[n][sum] = (subsetSumFind(nums, sum-nums[n-1], n-1) || subsetSumFind(nums, sum, n-1));
        
        return t[n][sum] = subsetSumFind(nums, sum, n-1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);

        if(sum%2 != 0) return false;
        
        int W = sum/2;
        int n = nums.size();
        t.resize(n+1, vector<int>(W+1, -1));
        return subsetSumFind(nums, W, n);
    }
};