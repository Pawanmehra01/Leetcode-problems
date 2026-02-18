class Solution {
public:
    bool hasAlternatingBits(int n) {
        
        while(n!=0){
            int op1 = n&1 ;
            n = n>>1 ;
            int op2 = n&1;
            if(op1 ==  op2)return false;
           
        }
        return true ;
        
    }
};