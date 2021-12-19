
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        
        
        vector<int> adj[105];
        int vis[105][105];
        int pos[105][105];
        
        
        for(int i=0;i<=103;i++)
        {
            for(int j=0;j<=103;j++)
            {
                vis[i][j]=0,pos[i][j]=0;
            }
        }
        
        
        vector<bool> ans;   
        for(int i=0;i<prerequisites.size();i++) 
        {
            int f = prerequisites[i][0];
            int s = prerequisites[i][1];
            adj[f].push_back(s);
        }
        
        for(int s=0;s<n;s++)
        {
            queue<int> q;
            q.push(s);
            while(!q.empty())
            {
                int cur = q.front();
                q.pop();
                for(int i=0;i<adj[cur].size();i++)
                {
                    int child = adj[cur][i];
                    //cout<<"here"<<" "<<child<<" "<<vis[child];
                    if(!vis[s][child])
                    {
                        //cout<<child<<"->";
                        pos[s][child]=1;
                        q.push(child);
                        vis[s][child]=1;
                    }   
                }
            }
        }
        
        
        for(int i=0;i<queries.size();i++)
        {
            int f = queries[i][0];
            int s = queries[i][1];
            bool fans = pos[f][s];
            ans.push_back(fans);                
            
        }
        
        return ans;
        
        
        
    }
};