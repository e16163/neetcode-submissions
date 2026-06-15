class TrieNode {

public: 
bool end;
map<char, TrieNode*> children;
    TrieNode()
    {
        end = false;
        map<char, TrieNode*> children;
    }
};
class PrefixTree {
public:
TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c: word)
        {
            if (curr->children[c]==nullptr)
            {
                curr->children[c] = new TrieNode();
            }
            curr = curr->children[c];
        }
        curr->end = true;

    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c: word)
        {
            if (curr->children[c]==nullptr)
            {
                return false;
            }
            curr = curr->children[c];
        }
        if (!curr->end)
        {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix)
        {
            if (curr->children[c]==nullptr)
            {
                return false;
            }
            curr = curr->children[c];
        }
        return true;
    }
};
