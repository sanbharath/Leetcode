class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int ans = 0;
        
        st.push(0);
        
        for(int i=0;i<s.size();i++){
            
            if(s[i] == '('){
                st.push(0);
            }
            else{    
                if(st.size() > 1){
                    int extra = st.top() + 1;
                    st.pop();
                    int prev = st.top();
                    st.pop();
                    st.push(prev + extra);
                    ans = max(ans,st.top());
                }  
                else{
                    int t = st.top();
                    st.pop();
                    ans = max(ans,t);
                    st.push(0);
                }
                        
            }
        
        }
        

        return 2*ans;
        
    }
};