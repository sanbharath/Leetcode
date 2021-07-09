class Solution {
public:
    
    int memo[5001][2];
    
    int maxProfit(vector<int>& prices) {
        // buy or sell
        // index
        // prices
        memset(memo,-1,sizeof(memo));
        int ans = findMax(0,0,prices);
        return ans;
    }
    
    int findMax(bool bought,int ind,vector<int>& prices){
        
        if(memo[ind][bought]!=-1)
            return memo[ind][bought];
        
        if (ind>=prices.size())
            return 0;

        //case
        // max
        // 1. bs=0 
            // max
            // 1.1 - prices[ind] + (bought^1, ind+1 , prices)
            // 1.2 (bought, ind+1, prices)
        // 2. bs=1
            // max
            // 2.1 prices[ind] + (val , bought^1, ind+2, prices)
            // 2.2 (bought, ind+1, prices)
        
        int coolDown = findMax(bought, ind+1, prices);
        if(bought==0){
            int selling = -prices[ind] + findMax(bought^1, ind+1 , prices);
            return memo[ind][bought] = max(selling,coolDown);
        }
        else{
            int buying = prices[ind] + findMax(bought^1, ind+2, prices);
            return memo[ind][bought] = max(buying,coolDown);
        }

    }
    
};