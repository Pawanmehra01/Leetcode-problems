class Solution {
public: 
  
    // int dp[10001][2][3] ;
    // int res(vector<int>&prices , int buy , int i, int trans ){
    //     if(trans <= 0)return 0 ; 
    //     if(i>=prices.size())return 0 ;
    //     if(dp[i][buy][trans] != -1 ) return dp[i][buy][trans] ;
    //     int profit  = 0 ;
    //     if(buy==0){
    //         //take not take
    //         profit  = max(-prices[i] + res(prices,1,i+1,trans ),
    //                     0 + res(prices,0,i+1,trans ));
    //     }else{
    //         //take not _take
    //         profit = max(prices[i] +res(prices ,0 ,i+1 ,trans-1),
    //                     0 + res(prices,1 ,i+1, trans));
    //     }
    //     dp[i][buy][trans] = profit;
    //     return dp[i][buy][trans] ;
    // }
    int maxProfit(vector<int>& prices) {
    
        
      
        vector<vector<vector<int>>>dp( prices.size()+1 ,vector<vector<int>>(2 ,vector<int>(3,0)));
        for( int index = prices.size()-1; index >= 0 ;index -- ){     
            for( int buy = 0 ;buy<=1 ; buy++){
                for( int trans = 1 ;trans <=2 ;trans++){
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
        return dp[0][0][2] ;
    }
};