class Solution {
public:
int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>xleft;
        unordered_map<int,int>xright;
        int n = nums.size();
     
        for( auto num:nums){
            xright[num]++ ;
        }
        int ans = 0 ;
      
        for(int i = 0 ;i< n;i ++){
            xright[nums[i]]--;
            int left  = xleft[nums[i]*2];
            int right = xright[nums[i]*2];
            ans = (ans +(1LL * left * right))%M ;
            xleft[nums[i]]++;
           
        }
        return ans ;
    
    }
};