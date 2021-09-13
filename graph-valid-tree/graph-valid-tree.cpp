class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        
        if(edges.size() == 0)
        {
            if(n==1)
                return 1;
            else
                return 0;
        }
        
        map<int,vector<int>> adj;
        
        for(auto edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        stack<int> st;
        st.push(0);
        map<int,int> parent;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto neighbour: adj[node]){
                
                if(parent[node] == neighbour){
                    continue;
                }
                if(parent.find(neighbour)!= parent.end()){
                    return false;
                }
                
                st.push(neighbour);
                parent[neighbour] = node;
            }
        }
        
        return parent.size() == n;
        
        
    }
};