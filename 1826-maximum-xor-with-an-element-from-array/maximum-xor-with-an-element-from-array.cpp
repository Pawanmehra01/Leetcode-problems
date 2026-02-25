class Solution {
public:
    struct TrieNode {
        TrieNode* right ;
        TrieNode* left ;
        TrieNode(){
            left=right=nullptr;
        }
    };
    void insert(TrieNode* root , int &num ){
        TrieNode * pCrawl = root ;

        for( int i = 31 ;i >=0 ;i --){
            int ith_bit = (num>>i) & 1  ;

            if(ith_bit == 0){
                if(pCrawl->left ==NULL){
                    pCrawl->left = new TrieNode();   
                }
                pCrawl =  pCrawl->left ;

            }else{
                if(pCrawl->right == NULL){
                    pCrawl->right = new TrieNode();
                }
                pCrawl = pCrawl->right;
            }

        }

    }
    int findMaxXOR(TrieNode *root , int &num ){
        int maxXOr = 0 ;
        TrieNode * pCrawl = root ;

        for(int i = 31 ;i >=0 ;i --){
            int ith_bit = (num>>i)&1 ;
            if(ith_bit == 1){
                if(pCrawl ->left != NULL ){
                    maxXOr += pow(2,i) * 1 ;
                    pCrawl = pCrawl -> left ;
                }else{
                    maxXOr += pow(2,i) * 0;
                    pCrawl = pCrawl -> right ;
                }
            }else{
                if(pCrawl ->right != NULL){
                    maxXOr += pow(2,i)*1;
                    pCrawl = pCrawl ->right ;
                }else{
                    maxXOr += pow(2,i) * 0;
                    pCrawl = pCrawl ->left ; 
                }
            }
        }
        return maxXOr;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());

        vector<pair<int,pair<int,int>>>offline;

        for(int i = 0;i<queries.size() ;i ++ ){
            offline.push_back({queries[i][1],{queries[i][0], i }});
        }

        sort(offline.begin() , offline.end()) ;
        int n = offline.size() ;

        TrieNode* root  = new TrieNode() ;
        vector<int>result(n , -1);
        int index = 0 ;

        for(int i = 0 ;i < n ; i ++ ){
            int mi = offline[i].first ;
            int idx = offline[i].second.second ;
            int xi  = offline[i].second.first ; 
            
           
            while(index < nums.size()  &&  nums[index] <= mi ){ 
                
                insert(root,nums[index]) ;
                index++;
            }
           
            if(index > 0 )result[idx] = findMaxXOR(root,xi) ;
            
        }
        return result ;

    }
};