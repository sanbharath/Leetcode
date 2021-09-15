/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    map<Node*,Node*> nodeMapping;
    
    Node* dfs(Node* node){
        
       // cout<<node->val<<" ";
        Node* copy = new Node(node->val,{});
        nodeMapping[node] = copy;
        
        for(auto neighbor:node->neighbors){
            if(nodeMapping.find(neighbor)!=nodeMapping.end()){
                nodeMapping[neighbor]->neighbors.push_back(copy);
                //copy->neighbors.push_back(nodeMapping[neighbor]);                
            }
            else{
                Node* duplicateNeighbor = dfs(neighbor);   
                //copy->neighbors.push_back(duplicateNeighbor);
                duplicateNeighbor->neighbors.push_back(copy);
            }
        }
        
        return copy;
    }
    
    
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)
            return NULL;
        
        Node* ans = dfs(node);
        
        return ans;
    }
};