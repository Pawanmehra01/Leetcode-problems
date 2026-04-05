class Solution {
public:
    bool judgeCircle(string moves) {
        int count_u = 0;
        int count_r = 0;
        int count_l = 0;
        int count_d = 0;

        for(int i = 0 ;i < moves.length();i ++){
            if(moves[i] == 'U')count_u++ ;
            if(moves[i] == 'R')count_r++;
            if(moves[i] == 'L')count_l++;
            if(moves[i] == 'D')count_d++;
            
        }if((count_l == count_r) && (count_u == count_d))return true;
        else return false;
    }
};