class Solution {
public:

    bool compare(int i,int j,string s, string p){
        
        if(i >= s.size())
            return 0;
        
        if(p[j] != '.')
            return s[i] == p[j];
        
        return 1;
        
    }
    
    bool check(int i,int j,string source,string pattern,vector<vector<int>> &dp){
        
        if(dp[i][j]!=-1){
            if(dp[i][j])
                return 1;
            else             
                return 0;
        }

        if((i >= source.size()) && (j >= pattern.size())){
            return dp[i][j] = 1;
        }
        
        if(j >= pattern.size())
            return dp[i][j] = 0;
        
        // Next character in patter is a star
        
        if((j+1 < pattern.size()) && pattern[j+1] == '*'){
            
            bool res1 = 0;
            bool res2 = 0;
            
            res1 = check(i, j+2, source, pattern,dp);
            if(compare(i,j,source,pattern)){
                res2 = check(i+1, j, source, pattern,dp);
            }
            
            return dp[i][j] = (res1 || res2 );
        }
        else{
            
            bool res1 = compare(i,j,source,pattern);
            if(res1)
                return dp[i][j] = check(i+1, j+1, source, pattern,dp);
            else
                return dp[i][j] = 0;
        }
        
    
    }
    
    bool isMatch(string s, string p) {
        
        vector<vector<int>> dp(s.size()+1,vector<int>(p.size()+1,-1));
        return check(0,0,s,p,dp);    
        dp.clear();
    }
};