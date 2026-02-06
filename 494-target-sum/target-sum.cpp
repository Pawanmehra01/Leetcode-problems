class Solution {
public:
    int targetSum(vector<int>&nums , int target ,int i,int sum ){
        if(target==sum && i >=nums.size())return 1 ;
        if(i>=nums.size() && target!= sum)return 0;
        

        int add = targetSum(nums,target,i+1,sum+nums[i]); 
        int subtract= targetSum(nums,target, i+1, sum-nums[i]);

        return add+subtract ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int i = 0 ;
        return targetSum(nums,target, i, 0);
    }
};