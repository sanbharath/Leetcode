typedef long long ll;

class Solution {
public:
    
    int count = 0;
    
    void merge(int l,int mid,int r,vector<int>& nums){
        
        vector<int> temp;
        
        // left  right
        // left > 2*right
        
        ll left = l;
        ll right = mid + 1;
        
        while((left<=mid) && (right<=r)){
            
            ll whyOverflow = 2 * (long long)nums[right];
            
            if(nums[left] > whyOverflow){
                ++right;
                count += (mid - left + 1);
            }
            else{
                ++left;
            }    
        }
        
        left = l;
        right = mid + 1;
        
        while((left<=mid) && (right<=r)){
        
            if(nums[left] > nums[right]){
                temp.push_back(nums[right]);
                ++right;
            }
            else{
                temp.push_back(nums[left]);
                ++left;
            }    
            
        }
        
        while(left<=mid){
            temp.push_back(nums[left]);
            ++left;
        }
        
        while(right<=r){
            temp.push_back(nums[right]);
            ++right;
        }
        

        for(int i=0;i<temp.size();i++){
            nums[i+l] = temp[i];
        }
        
        temp.clear();
                
    }
    
    void mergeSort(int l,int r,vector<int>& nums){
        
        if(l<r){
            
            int mid = (l + r)/2;
            
            mergeSort(l,mid,nums);
            mergeSort(mid+1,r,nums);
            merge(l,mid,r,nums);
        } 
        
    }
    
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        count = 0;
        
        mergeSort(0, n-1, nums);
        
        for(auto num:nums){
            cout << num << " ";
        }
        
        return count;
    }
};