class Solution {
public:
    bool palindrome(int i , int j , string &s){
        if(i>=j)return true ;
        if(s[i]==s[j]){
            return palindrome(i+1,j-1,s);
        }
        return false ;
    }

    string longestPalindrome(string s) {
        int max_len = INT_MIN ;
        int sp = 0 ;
        int n = s.size();
            for(int i = 0 ; i< n ; i++ ){
                for(int j = i ;j < n ; j ++){
                    if(palindrome(i,j,s)){
                        if(j-i+1>max_len){
                            max_len = j-i+1;
                            sp = i;
                        }
                    }
                }
            }
            return s.substr(sp,max_len);

    }
};