class Solution {
public:
   void solve(vector<int>&nums , vector<vector<int>>& res , int i , int  n ){

        if(i==n){
            res.push_back(nums);
            return ;
        }
        set<int>st ;
        for( int j = i ;j <n ;  j ++ ){
            if(st.count(nums[j]))continue;
             
            st.insert(nums[j]);
            swap(nums[i],nums[j]);
            solve(nums,res,i+1, n);
            swap(nums[j],nums[i]);
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res ;
        solve(nums,res, 0 , n );
        return res ;
        
    }
};