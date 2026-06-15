class TrieNode {
public: 
bool end;
vector<TrieNode*> children;
    TrieNode()
    {
        end = false;
        children = vector<TrieNode*>(26);
        
    }
};
class WordDictionary {
TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c: word)
        {
            int ind = c - 'a';
            if (curr->children[ind]==nullptr)
            {
                curr->children[ind] = new TrieNode();
            }
            curr = curr->children[ind];
        }
        curr->end = true;
    }
    
    bool search(string word) {
        bool ans = false;
        TrieNode* curr = root;
        dfs(word, curr, ans, 0);
        return ans;
    }
    void dfs(string& word, TrieNode* curr, bool& ans, int i)
    {
        if (ans)
        {
            return;
        }
        if (i >= word.length())
        {
            if (curr->end)
            {
                ans = true;
                return;
            }
            return;
        }
        char c = word[i];
        if (c =='.')
        {
            for (auto& n: curr->children)
            {
                if (n)
                {
                    dfs (word, n, ans, i + 1);
                }
            }
        }
        else 
        {
            int ind = c - 'a';
            if (curr->children[ind] != nullptr) {
                dfs(word, curr->children[ind], ans, i + 1);
            }
        }
        
        
    }

};
