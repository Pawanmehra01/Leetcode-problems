class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length() ;
        unordered_set<char>indi ;
        for( int  i = 0 ; i< n ;i ++){
            char c= s[i] ;
            indi.insert(c);
        }
        int ans = 0 ;
        for( auto num : indi){
        int left  = -1 ;
        int right = 0 ;
        for( int i = 0 ; i< n ;i++){
                if( num == s[i]){
                    if(left == -1){
                       left  = i ;cout<<"l"<<s[i]<<endl;
                    }
                    right = i ;
                    cout<<"r"<<s[i]<<endl;
                }
        }   unordered_set<char >ans1  ;
            for( int k = left +1; k <right ; k++){
                    
                    ans1.insert(s[k]);
            }
            ans += ans1.size();
            cout<<ans;
           
       }
        return ans ;
    }
};