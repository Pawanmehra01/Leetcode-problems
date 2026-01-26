class Solution {
public:
    /* here stones is stones vector prevjump = k  and j is current index
    from which we have to check the index */
    int dp[2001][2001];
    bool canReach(vector<int>&stones,int prevjump,int j,
                int n,unordered_map<int,int>&mp ){
            /* base case */
            if(n-1 == j)return true ;
             
            if(dp[prevjump][j]!= -1)return dp[prevjump][j] ;

            bool res = false ;

                for(int nextjump = prevjump-1 ;nextjump <= prevjump+1 ;nextjump++ ){
                    if(nextjump>0){
                       int nextstone = stones[j]+nextjump ;
                       if(mp.find(nextstone)!= mp.end()){
                        cout<<res<<"res"<<endl;
                        res= res|canReach(stones,nextjump,mp[nextstone],n,mp);
                       }
                    }
                }
            
        return dp[prevjump][j]  = res ;
    }    
        bool canCross(vector<int>& stones) {

        if(stones[1]!=1)return false ;

        int n = stones.size();

        unordered_map<int,int>mp ;
        for(int i = 0;i < n ;i++){
            mp[stones[i]] = i ;
        }
        memset(dp,-1,sizeof(dp));

        return canReach(stones,0,0,n,mp);
    }
};