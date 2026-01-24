class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int i =0 ;
        int j = n-1;
        int mx = 0 ;
        sort(nums.begin(),nums.end());
        while(i<j){
            int sum = nums[i]+nums[j];
            mx = max(mx,sum);
            i++ ;
            j--;
        }
        return mx ;
    }
};