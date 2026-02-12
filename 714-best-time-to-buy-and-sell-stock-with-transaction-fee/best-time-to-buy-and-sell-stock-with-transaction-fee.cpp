class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp( prices.size()+2,(vector<int>(2,0)));
        for( int index = prices.size()-1; index >=0 ;index -- ){     
            for( int buy = 0 ;buy<=1 ; buy++){
               
                    int profit = 0 ;
                        if(buy==0){
                        //take not take
                            profit  = max(-prices[index] + dp[index+1][1],
                                    0 + dp[index+1][0]);
                        }
                        else{
                        //take not _take
                            profit = max(( prices[index] +dp[index+1][0])-fee,
                                    0 +dp[index+1][1]);
                        }
                    dp[index][buy] = profit;
                    
            }
        }
        return dp[0][0] ;
    }
};