class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())
            return 0;
        
        map<char,int> sCount;
        map<char,int> tCount;
        
        for(int i=0;i<s.size();i++){
            sCount[s[i]]++;
            tCount[t[i]]++;
        }
        
        for(auto sMap:sCount){
            if(tCount[sMap.first] != sMap.second){
                return 0;
            }
        }
        
        return 1;
    }
};