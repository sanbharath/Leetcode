class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> countArray;
        countArray[0] = 1;
        
        int prefixSum = 0;
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            int requiredNum = prefixSum - k;
            ans += countArray[requiredNum];
            countArray[prefixSum]++;
        }
        
        return ans;
        
        
    }
};