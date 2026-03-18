class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        int n = mountain.size() ;
        if(n==2)return {};
        vector<int>indexes;

        for(int i = 1 ;i < n-1 ;i ++ ){
            if(mountain[i-1]<mountain[i] && mountain[i] > mountain[i+1])
            indexes.push_back(i);
        }
        return indexes ;
    }
};