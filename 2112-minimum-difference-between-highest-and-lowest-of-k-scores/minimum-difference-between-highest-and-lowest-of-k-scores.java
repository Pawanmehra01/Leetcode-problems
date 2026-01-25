class Solution {
    public int minimumDifference(int[] nums, int k) {
        int n = nums.length;
        Arrays.sort(nums);
        int minAns = Integer.MAX_VALUE;
        int i = 0 ;
        int j = k-1 ;
        while(j < n){
            int max = nums[j];
            int min  = nums[i];
            minAns = Math.min(minAns , max-min) ;
            i++;
            j++;
        }
        return minAns;
    }
}