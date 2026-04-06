struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        TrieNode* root = new TrieNode();
        for (const string& s : strs)
        {
            insert(root, s);
        }

        string prefix = "";
        TrieNode* node = root;

        while (node->children.size() == 1 && !node->isEnd)
        {
            auto it = node->children.begin();
            prefix += it->first;
            node = it->second;
        }

        return prefix;
    }

    void insert(TrieNode* root, const string& word)
    {
        TrieNode* node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }

        node->isEnd = true;
    }
};