class Solution {
public:
   
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
 
        int prev1  = nums[0];
        int prev2  = nums[0];
        int res = nums[0];
        for( int i = 1 ;i < n ;i ++ ){
            
            int mn= min({nums[i]*prev1,nums[i]*prev2,nums[i]});
            int mx= max({nums[i]*prev2,nums[i]*prev1,nums[i]});
            prev1 = mn ;
            prev2 = mx ; 
            
            res= max(res,mx);
    }

    return res;
    }
};