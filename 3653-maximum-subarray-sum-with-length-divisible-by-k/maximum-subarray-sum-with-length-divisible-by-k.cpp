class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n  = nums.size();
        vector<long long> mn(k, LLONG_MAX);
        long long sum = 0;     // prefix sum
        long long ans = LLONG_MIN;
        
        mn[0] = 0;   // prefix[0]

        for(long long i = 0; i < n; i++){
            sum += nums[i];
            
            long long mod = (i + 1) % k;

            if(mn[mod] != LLONG_MAX){
                ans = max(ans, sum - mn[mod]);
            }

            mn[mod] = min(mn[mod], sum);
        }

        return ans;
    }
};