class TrieNode {
public:
       TrieNode* children[26];
       bool endOfWord;

       TrieNode() { //when a new node is created all children are set to nullptr
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false; // by default this node is not the end of the word
       }
};
class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a'; // gives index of the letter eg. d == 3;
            if (cur->children[i] == nullptr) {
                cur->children[i] = new TrieNode();
            }
            cur  = cur->children[i];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr) {
                return false;
            }
            cur = cur->children[i];
        }
        return true;
    }
};
