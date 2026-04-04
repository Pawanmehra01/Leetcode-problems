class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length() ;
        int columns = (n)/ rows ;
        string ans = "";
        vector<vector<char>>newvec(rows,vector<char>(columns,' '));
        int traverse = 0 ;
        for(int i = 0 ;i <rows ;i ++ ){
            for(int j = 0 ;j < columns ;j ++ ){
                if(traverse >= n)break;
                   newvec[i][j] = encodedText[traverse];
                   traverse++;
            }
        }
        
        for( int col  = 0 ; col < columns ;col ++){
            int row  = 0 ;
            int c = col ;
            while(row<rows && c<columns){
                ans += newvec[row][c];
                row++;
                c++;
            }
        }
            for(int i = ans.length() -1 ; i>=0 ;i --){
                if(ans[i] == ' '){
                    ans.pop_back();
                }else break;
            }
            return ans ;

    }
};