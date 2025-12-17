class Solution {
public:
    void solve(vector<string>&res,int i, string digits,string ans,unordered_map<char,string>&mp){
        if(i == digits.length()){
            res.push_back(ans);
            return ;
        }
        string alpha = mp.at(digits[i]);
        for(auto digit:alpha){
            solve(res,i+1,digits ,ans+digit,mp) ;
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res ;
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        if (digits.empty()) {
            return res;
        }
        solve(res,0,digits,"",mp);
        return res  ;


    }
};