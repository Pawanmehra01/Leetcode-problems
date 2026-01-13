class LRUCache {
    struct Node {
        int value, key;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };

public:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        mp.clear();
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void deletenode(Node* node) {
        Node* prevle = node->prev;
        Node* afternode = node->next;
        prevle ->next = afternode;
        afternode ->prev = prevle;
    }
    void afterNode(Node* node) {
        Node* curr = head->next; // head  <-newelement  <-curr  8 tail
        curr->prev = node;
        head->next = node;
        node->prev = head;
        node->next = curr;
    }
    int get(int key) {
        if (mp.find(key)== mp.end())
            return -1;
        Node* node = mp[key];
        deletenode(node);
        afterNode(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            deletenode(node);
            afterNode(node);

        } else {
            if (mp.size() == capacity) {
                Node* node = tail->prev;
                mp.erase(node->key);
                deletenode(node);
            }
            Node* add = new Node(key, value);
            mp[key] = add;
            afterNode(add);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */