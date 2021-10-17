// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        
        int x = rand7();
        int y = rand7();
        
        int v = (x-1)*7 + y;
        if(v>=41)
            return rand10();
        
        return 1 + v%10;
        
        
    }
};