class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int l = 0 ;
        int r = 0 ;
        int satisfied = 0 ;
        while(l<n && r<m){
            if(s[r] >=g [l]){
                satisfied++;
                r++;
                l++;
            }
                else if(s[r]<g[l]){
                       r++;
                    }
                    else{
                        l++;
                    }
        }
        return satisfied;
    }
};         