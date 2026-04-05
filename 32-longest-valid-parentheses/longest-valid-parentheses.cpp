class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length() ;
        int left_count = 0 ;
        int right_count = 0 ;
        int max_valid = 0 ;
        for(int i = 0 ;i < n ;i ++ ){
            if(s[i] == '(')left_count++ ;
            if(s[i] == ')')right_count++ ;
            if(right_count > left_count){
                right_count = 0 ;
                left_count = 0 ;
            }if(left_count ==right_count){
                max_valid = max(max_valid , left_count + right_count) ;
            }
        }       
        left_count = 0 ;
        right_count = 0 ; 
        for(int i = n-1 ;i >= 0 ; i-- ){
            if(s[i] == '(')left_count++ ;
            if(s[i] == ')')right_count++ ;
            if(right_count < left_count){
                right_count = 0 ;
                left_count = 0 ;
            }if(left_count ==right_count){
                max_valid = max(max_valid , left_count + right_count) ;
            }
        }  
        return max_valid;
    }
};