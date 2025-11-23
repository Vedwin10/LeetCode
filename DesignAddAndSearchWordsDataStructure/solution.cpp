class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        dict_.insert(word);
    }
    
    bool search(string word) {
        vector<int> dots;
        for (int i = 0; i < word.size(); ++i) if (word[i] == '.') dots.push_back(i);
        if (dots.size() == 0) return dict_.find(word) != dict_.end();
        else if (dots.size() == 1) {
            for (int i = 0; i < 26; ++i) {
                char c = 'a' + i;
                string temp = word;
                temp[dots[0]] = c;
                if (dict_.find(temp) != dict_.end()) return true;
            }
        } else if (dots.size() == 2) {
            for (int i = 0; i < 26; ++i) {
                char c = 'a' + i;
                string temp = word;
                temp[dots[0]] = c;
                for (int j = 0; j < 26; ++j) {
                    char c2 = 'a' + j;
                    temp[dots[1]] = c2;
                    if (dict_.find(temp) != dict_.end()) return true;
                }
            }
        }
        return false;
    }
private:
    unordered_set<string> dict_;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);d
 * bool param_2 = obj->search(word);
 */

// Pretty straightforward, hashset of all added words, for dots we can just check hashmap while substituting all 26 English letters and checking
// Since there is a constraint of 2 dots, a double for loop that runs 26 times is ok
// Could use dfs, but for these constraints this method is not significantly slower
