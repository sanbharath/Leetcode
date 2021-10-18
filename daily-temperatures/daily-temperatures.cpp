class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
                
        stack<int> s;
        s.push(0);
        int n = temperatures.size();
        
        vector<int> ans(n,0);
        
        for(int i=1;i<temperatures.size();i++){
            
            int t = s.top();
            if(temperatures[t]>=temperatures[i]){
                s.push(i);
            }
            else{
                while(temperatures[t]<temperatures[i]){
                    ans[t] = i - t;
                    s.pop();
                    if(s.size()<=0)
                        break;
                    t = s.top();
                }
                s.push(i);
            }
            
        }
        
        return ans;
    
    }
    
};