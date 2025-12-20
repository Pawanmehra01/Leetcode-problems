class Solution {
public: 
    void solve(vector<int>&nums,int i , int ansXor,int &sumofEACHsubset){
        if(i>=nums.size()){
            sumofEACHsubset += ansXor ;
            return ;
        }
       
        solve(nums,i+1,nums[i]^ansXor,sumofEACHsubset);
    
        solve(nums,i+1,ansXor,sumofEACHsubset);

    }
    int subsetXORSum(vector<int>& nums) {
        int i = 0 ;
        int ansXor =0 ;
        int sumofEACHsubset = 0;
        solve(nums,i,ansXor,sumofEACHsubset);
        return sumofEACHsubset ;
    }
};