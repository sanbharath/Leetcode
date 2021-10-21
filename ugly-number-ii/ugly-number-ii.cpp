class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> dp;
        
        int cnt = 0;
        int curUgly = 1;
        dp.push_back(curUgly);
        
        int i=0, j=0, k=0;
        
        while(dp.size() < n){
            
            curUgly = min({dp[i]*2, dp[j]*3, dp[k]*5});
            if(curUgly == dp[i]*2)++i;
            if(curUgly == dp[j]*3)++j;
            if(curUgly == dp[k]*5)++k;
            
            dp.push_back(curUgly);
        }
        
        return dp[n-1];
        
    }
};