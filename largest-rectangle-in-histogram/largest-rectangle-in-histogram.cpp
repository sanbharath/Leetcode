class Solution {
public:
        
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> s;
        s.push(-1);
        
        int ans = 0;
        
        for(int i=0;i<heights.size();i++){
            
            while((s.top()!=-1) && (heights[s.top()]>= heights[i])){
                
                int curHeight = heights[s.top()];
                s.pop();
                int curWidth = i - s.top() - 1;
                ans = max(ans, curHeight*curWidth);
            } 
            s.push(i);

        }
        
        while(s.top()!=-1){
            
            int curHeight = heights[s.top()];
            s.pop();
            int curWidth = heights.size() - s.top() - 1;
            ans = max(ans, curHeight*curWidth);
        }
        
        return ans;
        
    }
};