class LRUCache {
    private:
    struct Node{
        int key , value ;
        Node* prev;
        Node* next;
        Node(int k , int v){
            key = k;
            value = v ;
            prev = nullptr;
            next = nullptr;
    }
};
public:
    int capacity_;
    map<int , Node*>mpp;
    Node* head;
    Node* tail;
LRUCache(int capacity) {
        capacity_=capacity;
       
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;  
}
void deletenode(Node* node){
       Node * prevNode=node->prev;
       Node* afterNode=node->next;
       prevNode->next=afterNode;
       afterNode->prev=prevNode;
    }
void insertAfterHead(Node* node){
        Node * curr = head -> next;
        head->next=node;
        node->prev=head;
        curr->prev=node;
        node->next=curr;
    }
    
int  get(int key) {
        if(mpp.find(key)==mpp.end())return -1;
        Node* node = mpp[key];
        deletenode(node);
        insertAfterHead(node);
        return node->value;        
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node = mpp[key];
            node->value = value ;
            deletenode(node);
            insertAfterHead(node);
        }else{
            if(mpp.size()==capacity_){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deletenode(node);
                delete node;
            }
            Node* node =new Node(key,value);
            mpp[key]=node;
            insertAfterHead(node);
        } 
      }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */