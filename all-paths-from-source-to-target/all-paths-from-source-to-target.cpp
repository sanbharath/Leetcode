class Solution {
public:
        
    vector<vector<int>> paths;
    vector<int> path;
    void dfs(vector<vector<int>>& graph, int cur){
            
        path.push_back(cur);
        
        if(cur==(graph.size()-1)) 
            paths.push_back(path);
        
        for(auto x: graph[cur]){
            dfs(graph,x);        
            path.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {    
        paths.clear();
        path.clear();
            
        dfs(graph,0);
        return paths;
    }
};