class Solution {
    public int minimumCost(int[] nums) {
        int n = nums.length;
        int mn = Integer.MAX_VALUE;
        int first = nums[0];
        
        for (int i = 1; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                mn = Math.min(nums[i] + nums[j], mn);
            }
        }
        
        return first + mn;
    }
}