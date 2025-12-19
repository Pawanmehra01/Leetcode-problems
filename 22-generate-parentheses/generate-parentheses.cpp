class Solution {
public:
    void solve(int open , int close , vector<string>&ans ,string add ){
        if(open == 0 && close == 0){
            ans.push_back(add);return ;
        }
        if(open>0){
            solve(open-1 ,close,ans,add+"(");
        }
        if(close>open)solve(open ,close-1 ,ans,add+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        
        int open = n ;
        int close = n ;
        solve(open , close, ans, "");
        return ans;


        
    }
};