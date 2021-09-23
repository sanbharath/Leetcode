class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        
        int bestAway = nums[0];
        int bestNear = max(nums[0], nums[1]);
        int bestHere = 0;
        
        for(int i=2;i<nums.size();i++){
            bestHere = max(bestAway + nums[i], bestNear);
            bestAway = bestNear;
            bestNear = bestHere;
        }
        
        return bestHere;
        
    }
};