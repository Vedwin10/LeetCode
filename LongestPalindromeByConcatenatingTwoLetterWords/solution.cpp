class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        unordered_map<string, int> palindromes;
        int ret = 0;
        for (const auto& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());

            if (rev == word) {
                palindromes[word]++;
                if (palindromes[word] == 2) palindromes.erase(word);
            }

            if (mp.find(rev) != mp.end() && mp[rev] != 0) {
                mp[rev]--;
                ret += 4;
            } else {
                mp[word]++;
            }
        }

        if (palindromes.size() > 0) ret += 2;
        return ret;
    }
};

// build a hashmap that counts each piece and its frequency
// if a piece's reverse exists, decrement that piece and add 4 to ret, simulate adding the pieces to the front and back of the word
// if a word is a palindrome, add it to the palindromes hashmap
// if the palindromes occurs twice, remove from palindroms hashmap, as it can be added to the front and back
// add 2 to ret if there exists at least 1 piece that is a palindrome, we can insert in middle of the final word
