class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList[0].size();
        int steps  = 1 ;
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string , int>>que ;
        que.push({beginWord,steps});
        while(!que.empty()){
            string word = que.front().first ;
            int steps = que.front().second ;
            string original = word;
            que.pop();
           
            for(int i = 0 ;i< n ;i++){
                
                for(char alpa = 'a' ; alpa<='z' ;alpa++){
                    word[i] = alpa ;
                    if(st.find(word)!=st.end()){
                        que.push({word,steps+1});
                        st.erase(word);
                    }      
                }
                word = original ;
            }
                if(word == endWord)return steps ;
        }
        return 0 ;

    }
};