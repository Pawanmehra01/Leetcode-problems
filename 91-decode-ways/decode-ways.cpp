class Solution {
public:
int t[1001];
int solve(string s,  int &count , int n,int i){
        if(i>=n){
           t[i]= 1 ;
        }
        if(s[i]=='0'){
           t[i] = 0 ;
        }
        if(t[i]!=-1){
            return t[i];
        }
        int result  = 0 ;
        result = solve(s,count,n,i+1);
        if(i<n-1){
           if(s[i]=='1' ||(s[i]=='2'&& s[i+1]<= '6')){
             result +=solve(s,count,n ,i+2 );
           }
        }
        return t[i]= result ;
       
}
    int numDecodings(string s) {
      int count = 0 ;
      int n = s.length() ;
      memset(t,-1,sizeof(t));
      return solve(s,count,n,0);
     
    }
};