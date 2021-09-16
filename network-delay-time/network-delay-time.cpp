class Solution {
public:
    
    
    void dijkstra(vector<pair<int,int>> adj[104], vector<int>& distance, int s){
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,s});
        distance[s] = 0;
        
        while(!pq.empty()){
            
            int cur_d = pq.top().first;
            int u = pq.top().second;
            
            pq.pop();
            
            for(auto v:adj[u]){
                
                if((cur_d + v.second) < distance[v.first]){
                    
                    distance[v.first] = (cur_d + v.second);
                    pq.push({distance[v.first], v.first});

                }   
            }   
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         
        vector<pair<int,int>> adj[105];
        vector<int> distance(105,1e7);
        
        for(auto edge:times){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }
        
        dijkstra(adj, distance, k);
        
        int ans = -1;
        
        
        for(int i=1;i<=n;i++){
            if(distance[i]!=1e7)
            {
                cout<< i <<" "<< distance[i] << endl;
                ans = max(ans, distance[i]);
            }    
            else{
                return -1;
            }
        }
        
        return ans;
        
    }
};