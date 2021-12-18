class Solution {
public:
    
    int dp[32][32];
    
    bool compare(int i,int j,string s, string p){
        
        if(i >= s.size())
            return 0;
        
        if(p[j] != '.')
            return s[i] == p[j];
        
        return 1;
        
    }
    
    
    bool check(int i,int j,string source,string pattern){
        
        if(dp[i][j]!=-1){
            if(dp[i][j])
                return 1;
            else             
                return 0;
        }

        if((i >= source.size()) && (j >= pattern.size())){
            return dp[i][j] = 1;
            /*
            
            if(j >= pattern.size() || (pattern[j] == '*' && (j+1 == pattern.size()))){
                return dp[i][j] = 1;
            }
            else{
                return dp[i][j] = 0;
            }
            */
            
        }
        
        if(j >= pattern.size())
            return dp[i][j] = 0;
        
        
        if(pattern[j] == '*')
            return dp[i][j] = check(i,j+1,source,pattern);
        
        
        if((j+1 < pattern.size()) && pattern[j+1] == '*'){
            
            bool res1 = 0;
            bool res2 = 0;
            bool res3 = 0;
            
            
            res1 = check(i, j+1, source, pattern);
            
            if(compare(i,j,source,pattern)){
                
                res2 = check(i+1, j, source, pattern);
                    
                res3 = check(i+1, j+1, source, pattern);
                
            }
            
            return dp[i][j] = (res1 || res2 || res3);
        }
        else{
            
            bool res1 = compare(i,j,source,pattern);
            if(res1)
                return dp[i][j] = check(i+1, j+1, source, pattern);
            else
                return dp[i][j] = 0;
        }
        
    
    }
    
    bool isMatch(string s, string p) {
        
        for(int i=0;i<31;i++){
            for(int j=0;j<31;j++){
                dp[i][j] = -1;
            }
        }
        return check(0,0,s,p);        
    }
};