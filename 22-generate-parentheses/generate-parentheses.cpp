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
        // if (left > right || left < 0) return;
        // if (left + right == 0) {
        //     result.push_back(parens);
        //     return;
        // }
        // // parens.push_back('(');
        // collect(result, parens, left - 1, right);
        // parens.pop_back();
        // parens.push_back(')');
        // collect(result, parens, left, right - 1);
        // parens.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        
        int open = n ;
        int close = n ;
        solve(open , close, ans, "");
        return ans;


        
    }
};