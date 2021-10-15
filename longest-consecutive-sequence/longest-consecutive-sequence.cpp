class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_map<int,bool> numSet;
        
        for(auto num:nums){
            numSet[num] = 1;
        }
        
        int ans = 0;
        
        for(auto num: nums){
            
            if(!numSet[num - 1]){
                int temp = num;
                int streak = 1;
                
                while(numSet[temp+1]){
                    streak += 1;
                    temp += 1;
                }
                
                ans = max(ans, streak);
            }
            
        }
        
        return ans;
        
        
    }
};