class LRUCache {
    struct Node{
        int key  ;
        int value ; 
        Node* next ;
        Node* prev ;
        Node(int key , int value ){
            this-> key = key ;
            this-> value = value ;
            next = NULL ;
            prev = NULL ;
        }

    };
public:
    int capacity ;
    unordered_map<int,Node*>mp; 
    Node* head ;
    Node* tail  ;
    
    LRUCache(int capacity) {
        this->capacity = capacity ;
        mp.clear(); 
        tail = new Node(-1,-1) ;
        head = new Node (-1,-1) ;
        head ->next = tail ;
        tail ->prev = head  ;

    }
    void deletenode(Node* node){
        Node* prevNode  = node->prev ;
        Node* afternode = node ->next ;
        prevNode->next = afternode ;
        afternode ->prev = prevNode ;
    }
     void insertafterhead(Node* node ){
        Node* curr =  head ->next ;
        head->next = node ;
        node->prev = head ;
        curr->prev = node ;
        node->next = curr ;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1 ;
        Node * node = mp[key] ; 
        deletenode(node) ;
        insertafterhead(node);
        return node -> value ;
        }
        
    
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key] ;
            node->value = value ;
            deletenode(node);
            insertafterhead(node);
            }
            else{
            if(mp.size()==capacity){
                Node* node = tail->prev ;
                mp.erase(node -> key) ;
                deletenode(node) ;
            }
            Node* nde = new Node(key,value);
            mp[key] = nde ;
            insertafterhead(nde);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */