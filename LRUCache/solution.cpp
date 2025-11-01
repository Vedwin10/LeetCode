class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity), head_(nullptr), tail_(nullptr) {}
    
    int get(int key) {
        if (cache_.find(key) == cache_.end()) return -1;
        Node* temp = remove(key);
        insert(temp);
        return cache_[key]->value;
    }
    
    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            Node* temp = cache_[key];
            temp->value = value;
            remove(key);
            insert(temp);
        } else {
            Node* new_node = new Node(key, value);
            if (cache_.size() == capacity_) {
                Node* temp = remove(tail_->key);
                cache_.erase(temp->key);
                delete temp;
            }
            cache_[key] = new_node;
            insert(new_node);
        }
    }

    ~LRUCache() {
        Node* curr = head_;
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
private:
    // doubly linked list with insert at front
    // hashmap for O(1) access operations
    int capacity_;
    unordered_map<int, Node*> cache_;
    Node* head_;
    Node* tail_;

    Node* remove(int key) {
        Node* temp = cache_[key];
        if (temp == tail_) tail_ = temp->prev;
        if (temp == head_) head_ = temp->next;
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        temp->prev = temp->next = nullptr;
        return temp;
    }

    void insert(Node* node) {
        if (!head_ && !tail_) head_ = tail_ = node;
        else {
            node->next = head_;
            head_->prev = node;
            head_ = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// We use a doubly linked list to maintain the LRU ordering of the cache, where all new insertions happen at the front
// The LRU will always be at the tail_ pointer of the list
// Any time an element is accessed using get(), we simply remove the node from the list, and reinsert it at the front
// We can find the Node* associated with a key in O(1) time by having a map<key, Node*> of all elements currently in the cache