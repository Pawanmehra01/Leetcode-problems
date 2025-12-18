class Solution {
public:
    vector<int>ans ;
    void solve(vector<int>&nums, int n  , vector<vector<int>>&res,int k ,int i){
        
       
        if(ans.size() == k ){
           res.push_back(ans) ;
           return ;
        } 
        if(i >= n )return ;
        
        ans.push_back(nums[i]);
        solve(nums ,n ,res , k ,i+1 );
        ans.pop_back();
        solve(nums,n ,res, k , i+1) ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>nums;
        vector<vector<int>>res;
        for(int i = 1 ; i<=n ;i ++){
            nums.push_back(i);
        }
        int count = 0;
        //we can do it using counter also 
        solve(nums,n,res , k, 0);
        return res ;
        
    }
};