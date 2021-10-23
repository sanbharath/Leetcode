class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            
        deque<pair<int,int>> q;
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<k;i++){
           
            while(q.size()>0 && nums[i] >= q.back().first){
                q.pop_back();
            }
            q.push_back({nums[i],i});
            
        }
        ans.push_back(q.front().first);
        
        for(int i=k;i<n;i++){
            
            if((q.size()>0) && ((i-k) >= q.front().second))
            {
                q.pop_front();
            }
        
            while((q.size()>0) && (nums[i] >= q.back().first)){
                q.pop_back();
            }
            
            q.push_back({nums[i],i});
            ans.push_back(q.front().first);
        }
        
        
        return ans;
    }
};