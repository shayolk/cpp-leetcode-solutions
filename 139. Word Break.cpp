class Trie {
    struct Node {
        bool end;
        vector<Node*> next;

        Node() {
            end = false;
            next.resize(26, nullptr);
        }
    };

    Node* root;

    void dfs_insert(Node* node, int i, int& n, string& word) {
        if (i == n) {
            node->end = true;
            return;
        }
        int c = word[i] - 'a';
        if (!node->next[c]) {
            node->next[c] = new Node();
        }
        dfs_insert(node->next[c], i + 1, n, word);
    }

    bool dfs_search(Node* node, int i, int& n, string& word) {
        if (i == n) {
            return !!node->end;
        }
        int c = word[i] - 'a';
        if (!node->next[c]) {
            return false;
        }
        return dfs_search(node->next[c], i + 1, n, word);
    }

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        int n = word.size();
        dfs_insert(root, 0, n, word);
    }
    
    bool search(string word, int i, int n) {
        return dfs_search(root, i, n, word);
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* trie = new Trie();
        for (string& word: wordDict) {
            trie->insert(word);
        }
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && trie->search(s, j, i)) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
