class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int present = 0 ;
        int n  = s.length();
        for( int i=0 ;i<n ;i++ ){
            if(s[i]=='(' ){
                if(present>0)res+=s[i];
                present++;
            }
            else{
                if(s[i]==')'){
                    if(present>1)res+=s[i];
                    present--;
                }
            }
        }
        return res;
    }
};