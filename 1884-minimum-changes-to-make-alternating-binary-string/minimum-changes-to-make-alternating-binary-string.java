class Solution {
    public int minOperations(String s) {
        int zeroes = 0 ;
        int n = s.length() ;
        for(int i =0 ;i < s.length();i++){
            if(i%2 == 0){
                if(s.charAt(i) == '1')zeroes++;
            }else{
                if(s.charAt(i)=='0')zeroes++;
            }
        }
       int ans = Math.min(zeroes ,n-zeroes);
       return ans ;
    }
}