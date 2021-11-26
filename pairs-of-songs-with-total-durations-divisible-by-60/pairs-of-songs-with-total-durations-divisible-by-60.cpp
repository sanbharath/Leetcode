class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        map<int,int> mod;
        
        for(auto times:time){
            mod[times%60]++;
        }
        
        int ans = 0;
        
        for(auto times:time){
            int offset = 60 - (times%60);
            if(offset == 60) offset = 0;
            ans += (mod[offset]);
            if(offset == 30 || offset == 0)
                --ans;
        }
        
        return ans/2;
    }
};