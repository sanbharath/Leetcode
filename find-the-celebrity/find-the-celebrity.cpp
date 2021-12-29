/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    bool check(int possibleCelebrity, int n){
        
        for(int i=0;i<n;i++){   
            if(i == possibleCelebrity)
                continue;
            
            if(knows(possibleCelebrity,i) || !knows(i,possibleCelebrity))
                return false;
        }
        return true;
    }
    
    int findCelebrity(int n) {
        
        int possibleCelebrity = 0;
        
        for(int i=1; i<n; i++) {
            if(knows(possibleCelebrity, i)){
                possibleCelebrity = i;
            }
        }
        
        if(check(possibleCelebrity, n)){
            return possibleCelebrity;
        }
        
        return -1;
    }
};