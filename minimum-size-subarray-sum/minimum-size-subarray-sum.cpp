class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n = nums.size();
        
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = 1e5 + 2;
        while(right<n){
            
            sum += nums[right];
            ++right;
            
            while(sum >= target){
                ans = min(ans, right-left);
                sum -= nums[left];
                ++left;
            }
        }
        
        
        
        if(ans == 1e5+2)
            return 0;
        
        return ans;
        
    }
};