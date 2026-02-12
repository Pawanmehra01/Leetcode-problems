class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
           vector<vector<vector<int>>>dp( prices.size()+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for( int index = prices.size()-1; index >= 0 ;index -- ){     
            for( int buy = 0 ;buy<=1 ; buy++){
                for( int trans = 1 ;trans <=k ;trans++){
                    int profit = 0 ;
                        if(buy==0){
                        //take not take
                            profit  = max(-prices[index] + dp[index+1][1][trans],
                                    0 + dp[index+1][0][trans]);
                        }
                        else{
                        //take not _take
                            profit = max(prices[index] +dp[index+1][0][trans-1],
                                    0 +dp[index+1][1][trans]);
                        }
                    dp[index][buy][trans] = profit;
                    }
            }
        }
        return dp[0][0][k] ;
    }
};