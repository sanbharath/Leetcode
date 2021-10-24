class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        vector<int> diff;
        int n = gas.size();
        
        for(int i=0;i<gas.size();i++){
            diff.push_back(gas[i] - cost[i]);
        }
        int start = 0;
        int sum = 0;
        
        bool fl = 1;
        int end = 0;
        
        while(fl){
            
            sum += diff[end%n];
            //cout<<sum<<" ";
            if(sum < 0){
                end = (end + 1)%n;
                sum = 0;
                if(n==1 || end<=start)
                    return -1;
                else
                    start = (end)%n;
            }
            else{
                if((end+1)%n == start){
                    return start;
                }
                end = (end + 1)%n;
            }
        }
        
        return -1;
    }
};