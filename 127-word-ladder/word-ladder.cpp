class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) { 
        int n = wordList[0].size() ;
        unordered_set<string>st(wordList.begin(),wordList.end()) ;
        if(st.find(endWord) == st.end())return 0  ;
        int steps  = 1 ;
        queue<pair<string,int>>q ;
        q.push({beginWord , steps }) ;

        while(!q.empty()){
            string word = q.front().first ;
            int steps = q.front().second  ;
            q.pop() ;

            if(word == endWord)return steps  ; 

            string original = word;
            for( int j = 0 ;j < n ;j ++ ){
                for(char i = 'a' ; i <= 'z'; i ++){
                    word[j] = i ;
                    if(st.find(word)!=st.end()){
                        q.push({word , steps+1});
                        st.erase(word);
                    }
                    
                } word = original ;
            }
        }
        return 0 ;
    }
};