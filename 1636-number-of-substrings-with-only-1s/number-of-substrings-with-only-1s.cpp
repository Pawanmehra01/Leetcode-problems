class Solution {
public:
    long long mod = 1e9 + 7 ;
    int numSub(string s) {
        long long  count = 0 ;
        long long ans  =  0 ;

        for( char ch : s ){
            if(ch == '1')count++ ;

            else if(ch == '0'){
                ans += ((count *(count+1))/2) % mod;
                count = 0;
            }
        }
        ans += (count *(count+1)/2);
        return ans  ;
    }
};