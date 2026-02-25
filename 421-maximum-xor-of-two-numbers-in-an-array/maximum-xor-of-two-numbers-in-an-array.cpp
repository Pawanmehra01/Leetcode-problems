class Solution {
public:
    struct TrieNode {
        TrieNode* right ;
        TrieNode* left ;
    };
    void insert(TrieNode * root , int &num ){
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
    int findMaximumXOR(vector<int>& nums) {
        TrieNode * root = new TrieNode() ;
        for(int &num : nums){
            insert(root,num) ;
        }
        int result = 0 ; 

        for(int i =0 ;i <nums.size() ;i++){
            int temp = findMaxXOR(root,nums[i]) ;
            result = max(result , temp );
        }
        return result ;
    }
};