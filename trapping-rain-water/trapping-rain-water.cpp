class Solution {
public:
    
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);
        
        int maxi = 0;
        for(int i=1;i<n;i++){
            max_left[i] = max(height[i-1], maxi);
            maxi = max_left[i];
        }
        maxi = 0;
        for(int i=n-2;i>=0;i--){
            max_right[i] = max(height[i+1], maxi);
            maxi = max_right[i];
        }
        
        int water = 0;
        
        for(int i=0;i<n;i++){
            int mini = min(max_left[i],max_right[i]);
            if((mini-height[i]) > 0){
                water += (mini-height[i]);
            }
        }
        
        return water;
        
    }
    
};