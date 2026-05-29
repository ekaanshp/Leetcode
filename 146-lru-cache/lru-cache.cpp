struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;
    
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int cap;
    std::unordered_map<int, Node*> cache;
    Node left;
    Node right;
public:
    LRUCache(int capacity) : cap(capacity), left(0, 0), right(0, 0) {
        left.next = &right;
        right.prev = &left;
    }
    
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* prev = right.prev;
        Node* next = &right;
        prev->next = node;
        node->prev = prev;
        node->next = next;
        next->prev = node;
    }

    int get(int key) {
        if(cache.contains(key)){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.contains(key)){
            remove(cache[key]);
            cache[key]->value = value;
            insert(cache[key]);
        }  
        else{
            cache[key] = new Node(key, value);
            insert(cache[key]);
        }

        if(cache.size() > cap){
            Node* lru = left.next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */