class Solution {
public:
    int dp[501][501];
    long long mx = LLONG_MIN;
    int recursion(vector<int>&nums1,int n ,
    vector<int>&nums2, int m , int i , int j){
        if( i==n || j==m )return INT_MIN/2;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans1= nums1[i]*nums2[j]+ max(0,recursion(nums1, n, nums2, m, i + 1, j + 1)); 
        int ans2 = recursion(nums1,n,nums2,m,i+1,j);
        int ans3 = recursion(nums1,n,nums2,m,i ,j+1); 
        
        dp[i][j] = max({ans1,ans2,ans3});
        return dp[i][j];
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int  n  = nums1.size();
        int  m  = nums2.size();
        memset(dp,-1,sizeof(dp));
        return recursion(nums1,n,nums2,m , 0 , 0);
    }
};