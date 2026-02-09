class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int i = str1.length() ; 
        int j = str2.length() ;
        vector<vector<int>>dp(i+1,vector<int>(j+1,0));
        
           
            for( int r = 1 ;r <=i ; r++){
                for( int k = 1 ; k <=j ;k++){
                    if(str1[r-1] == str2[k-1]){
                        dp[r][k] = 1 + dp[r-1][k-1];
                    }
                    else{
                        dp[r][k]  = max(dp[r-1][k],dp[r][k-1]);
                    }
                }
            }

            string ans ="" ;
           
            while(i>0 && j>0){
                if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;j-- ;

                }
                else{
                    if(dp[i-1][j]>dp[i][j-1]){
                        ans.push_back(str1[i-1]);
                        i--;
                        
                    }else{
                        ans.push_back(str2[j-1]);
                        j--;
                    }
                }
            }
            while(i>0){
                ans.push_back(str1[i-1]);
                i--;
            }
            while(j>0){
                ans.push_back(str2[j-1]);
                j--;    
            }
        reverse(ans.begin(), ans.end());
        return ans ;       
        }
    };