class Solution {
public:
        static bool byend(vector<int>& f,vector<int>& s){
            return f[1] < s[1];
        }
    
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // claim : picking intervals with lower end time first gives optimal answer
        sort(intervals.begin(),intervals.end(),byend);
        int total = intervals.size();
        int ans = 0;
        int prevEnd = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
              
            int curStart = intervals[i][0];
            
            if(curStart < prevEnd){
                ++ans;   
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        
        return ans;
    }
};