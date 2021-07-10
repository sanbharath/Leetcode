class Solution {
public:
    
    const int MOD = 1e9+7;
    
    int countGoodNumbers(long long n) {
        
        long long evenCount = n/2;
        long long oddCount = evenCount;
        if(n&1)
            evenCount++;
        
        // Even ind options : 0 2 4 6 8
        // Odd  ind options : 2 3 5 7
        // 5^evenCount + 4^oddCount 
        
        long long ans = ((pows(5,evenCount)%MOD) * (pows(4,oddCount)%MOD))%MOD;
        return (int)ans;
    }
    
    // Binary Exponentiation - O(log n)
    long long pows(long long c,long long n){
        int res = 1;
        while(n){
            if(n&1)
                res=((res%MOD)*(c%MOD))%MOD, n--;
            else
                c=((c%MOD)*(c%MOD))%MOD, n=n>>1;
        }
        return res%MOD;
    }
    
};