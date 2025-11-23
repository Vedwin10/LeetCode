class Node {
public:
    char character;
    unordered_map<char, Node*> children;
    Node(char c) : character(c) {}
};

class Trie {
public:
    Trie() {
        root_ = new Node('*');
    }
    
    void insert(string word) {
        Node* curr = root_;
        int i = 0;
        for (; i < word.size(); ++i) {
            if (curr->children.find(word[i]) == curr->children.end()) break;
            curr = curr->children[word[i]];
        }
        for (; i < word.size(); ++i) {
            curr->children[word[i]] = new Node(word[i]);
            curr = curr->children[word[i]];
        }
        words_.insert(word);
    }
    
    bool search(string word) {
        bool res = false;
        Node* curr = root_;
        for (int i = 0; i < word.size(); ++i) {
            if (curr->children.find(word[i]) == curr->children.end()) {
                res = true;
                break;
            }
            curr = curr->children[word[i]];
        }
        return !res && (words_.find(word) != words_.end());
    }
    
    bool startsWith(string prefix) {
        bool res = false;
        Node* curr = root_;
        for (int i = 0; i < prefix.size(); ++i) {
            if (curr->children.find(prefix[i]) == curr->children.end()) {
                res = true;
                break;
            }
            curr = curr->children[prefix[i]];
        }
        return !res;
    }

    ~Trie() {
        destroy(root_);
    }
private:
    Node* root_;
    unordered_set<string> words_;

    void destroy(Node* node) {
        for (auto& [key, val] : node->children) {
            destroy(val);
        }
        delete node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// Use nodes with current character and children stored in a hashmap, mapping each char to its child Node*
// Use a hashset to keep track of previously inserted words
// Traverse tree using children for search, startsWith
