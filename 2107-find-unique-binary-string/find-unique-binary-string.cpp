class Solution {
public:

    int n;
    string ans;

    void solve(string &res, unordered_set<string>& store_string, int i){

        if(ans != "") return;

        if(i == n){
            if(!store_string.count(res)){
                ans = res;
            }
            return;
        }

        res.push_back('0');
        solve(res, store_string, i + 1);
        res.pop_back();

        res.push_back('1');
        solve(res, store_string, i + 1);
        res.pop_back();
    }

  
    string findDifferentBinaryString(vector<string>& nums) {
        //canters algorithm
        // string res = "" ;
        // int n = nums.size() ;
        // for(int i = 0 ;i < n ;i ++ ){
        //     char ch  = nums[i][i] ;
        //     res+=(ch == '0')?'1':'0';
        // }
        // return res ;
        string res = "";
        n = nums.size() ;
        unordered_set<string>store_string(nums.begin(),nums.end());
        
       solve(res,store_string,0);
       return ans ;
    }
};