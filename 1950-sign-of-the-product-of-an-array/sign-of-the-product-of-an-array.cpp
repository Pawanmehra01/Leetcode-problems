class Solution {
public:
    int arraySign(vector<int>& n) {
        int  prod = 1 ;
        int mod= 1e9;
        for(int i =0 ;i < n.size();i++){
            if(n[i] > 0)n[i]=1 ;
            else if(n[i]<0)n[i]=-1;

            prod= prod * n[i];
        }
        if(prod > 0)return 1 ;
        else if(prod<0)return -1;
        else return 0 ;
    }
};