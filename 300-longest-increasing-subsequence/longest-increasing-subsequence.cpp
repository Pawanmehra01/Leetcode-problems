class Solution {
public:
    

    int t[2501][2502];
    int helper(vector<int>&nums ,int n , int i , int prev ){
        if(i==n)return 0;
        if(t[i][prev+1]!=-1){
            return t[i][prev+1];
        }
        int a  = 0 ; 
        if(prev == -1 || nums[i]>nums[prev]){
            a =1+ helper(nums,n,i+1,i);
        }

        int  b = helper(nums,n,i+1,prev);
        return t[i][prev+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        memset(t,-1,sizeof(t));
        return helper(nums, n ,0,prev);
       
    }
};