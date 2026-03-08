class Solution {
public:

    int n;
    string ans;

    void solve(string res, unordered_set<string>& store_string, int i){

        if(ans != "") return;

        if(i == n){
            if(!store_string.count(res)){
                ans = res;
            }
            return;
        }

        solve(res + '0', store_string, i + 1);
        solve(res + '1', store_string, i + 1);
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