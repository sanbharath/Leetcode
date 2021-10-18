class Solution {
public:
    
    pair<int,int> apply(stack<int>& s){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        return {a,b};
    }
    
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto token:tokens){
            
            if(token == "+"){
                pair<int,int> nos = apply(s);
                s.push(nos.first + nos.second);
            }
            else if(token == "-"){
                pair<int,int> nos = apply(s);
                s.push(nos.second - nos.first);
            }
            else if(token == "/"){
                pair<int,int> nos = apply(s);
                s.push(nos.second / nos.first);
            }
            else if(token == "*"){
                pair<int,int> nos = apply(s);
                s.push(nos.second * nos.first);
            }
            else{
                s.push(stoi(token));
            }
            
        }
        
        return s.top();
    }
};