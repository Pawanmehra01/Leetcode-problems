class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length() ;
        if(n==1)return true ;
        bool zeroes = false;
        
        for(int i = 1 ;i < n ; i++){
           if(s[i]=='0')zeroes=true;
           if(s[i]=='1' && zeroes)return false;
        }
        
        return true;
    }
};