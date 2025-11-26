class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int mx= max({s1.length(),s2.length(),s3.length()}) ;
        int store = 0;
        if(s1[0]!=s2[0]|| s2[0]!=s3[0])return -1;
        int sum = s1.length() + s2.length() + s3.length(); // Sum of lengths of all three strings

        for( int i = 0  ; i<mx; i ++){
            char c = s1[i];
    
            if(s2[i]==c && c == s3[i]){sum -= 3;
            continue ;}
            
            break ;
        }
        
     return sum ;

    }
};