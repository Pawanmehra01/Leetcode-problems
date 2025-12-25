class Solution {
public:
    int t[1001];
    bool present(vector<string>&wordDict,string res){
        for(int i = 0 ; i < wordDict.size();i++){
            
            if(wordDict[i] == res){
                
                return true;
                
            }
        }
        return false;
    }
    bool helper(vector<string>&wordDict,string s ,string res ,int i,int n ){
        if(i==n){
            return res==""|| present(wordDict,res) ;
        }
        if(res==""&&t[i]!=-1){
            return t[i];
        }
        bool take  = helper(wordDict,s,res+s[i],i+1,n);
        
        bool not_take  = false;
        if(present(wordDict,res))
           not_take = helper(wordDict,s,"",i,n);
          
        bool ans  = take||not_take;
        if(res=="") t[i]= ans ;
        return ans ;
      }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n  = s.length();
        int i = 0;
        memset(t,-1,sizeof(t));
        return helper(wordDict, s , "" , i,n);
    }
};