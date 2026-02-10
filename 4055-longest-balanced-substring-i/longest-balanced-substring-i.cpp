class Solution {
public:
    bool check(vector<int>&count){
        int number = 0 ;
        for( int i = 0 ;i < 26 ; i++){
            if(count[i] == 0)continue; ;
            if(number == 0 ){
                number = count[i] ;
            }
            else if(number!=count[i])
            return false;

        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length() ;
        int len =  0 ;
    
        for(int i = 0 ; i< n ;i++){
            vector<int>count(26,0);

            for(int j = i;j< n ;j++){
               int element  = s[j]-'a' ;
               count[element]++;
               if(check(count))len = max(len,j-i+1) ;
            }
        }
        return len ;
    }
};