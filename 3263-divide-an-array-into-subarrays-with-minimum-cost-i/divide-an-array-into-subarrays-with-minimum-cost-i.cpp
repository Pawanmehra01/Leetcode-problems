class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int mn = INT_MAX ;
        int first = nums[0];
        for(int i = 1 ;i < n-1; i++ ){
            for(int j= i+1; j< n;j++){
            mn= min(nums[i]+nums[j],mn);
            }
        }
        return first+mn;
    }
};