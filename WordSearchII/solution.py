class TrieNode:
    def __init__(self, is_end=False, word=None):
        self.children = {}
        self.is_end = is_end
        self.word = word

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        res = set()

        # construct a Trie
        root = TrieNode()
        for word in words:
            curr = root
            for i, letter in enumerate(word):
                if letter not in curr.children:
                    curr.children[letter] = TrieNode()
                curr = curr.children[letter]
            curr.is_end = True
            curr.word = word

        # run dfs with backtracking on all nodes
        visited = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] in root.children:
                    self.dfs(board, i, j, root.children[board[i][j]], visited, res)

        return list(res)
    
    # dfs
    def dfs(self, board, x, y, node: TrieNode, visited, res):
        visited.add((x, y))
        if node.is_end:
            res.add(node.word)
        
        for dx, dy in [(-1, 0), (1, 0), (0, 1), (0, -1)]:
            nx, ny = x+dx, y+dy
            if 0 <= nx < len(board) and 0 <= ny < len(board[0]) and (nx, ny) not in visited:
                if board[nx][ny] in node.children:
                    self.dfs(board, nx, ny, node.children[board[nx][ny]], visited, res)

        visited.remove((x, y))

# essentially, we construct a trie from the words list given to us
# then we run dfs on all the characters on the board that start with a letter that is a first letter in a word in words
# we add the word to res if node in the trie is a word
# to make this faster, we could implement pruning given the fact that words are unique
