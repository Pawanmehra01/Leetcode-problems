class Solution {
public:
    int minOperations(string s) {
        int zeroes = 0 ;
        int n = s.length() ;
        for(int i =0 ;i < s.length();i++){
            if(i%2 == 0){
                if(s[i] == '1')zeroes++;
            }else{
                if(s[i]=='0')zeroes++;
            }
        }
       int ans = min(zeroes ,n-zeroes);
       return ans ;
        
    }
};