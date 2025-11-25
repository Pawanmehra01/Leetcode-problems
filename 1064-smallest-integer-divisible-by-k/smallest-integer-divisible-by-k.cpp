class Solution {
public:
    int smallestRepunitDivByK(int k) {
         int  remainder = 0;
         //pigeon hole principkle is used 
        if(k==2||k%2==0||k%5 == 0)return -1;
        for(int i = 1 ; i<=k ;i ++){
            remainder = ((remainder*10)+1) % k;
            if(remainder ==  0 ){
                return i ;
            }
        }
        return -1 ;
    }
};