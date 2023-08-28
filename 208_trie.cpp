#include "common.h"

class TrieNode {
    friend class Trie;
public:
    TrieNode(char value) :m_Value(value) {};

private:
    char m_Value;
    bool m_IsWord = false;
    unordered_map<char, std::shared_ptr<TrieNode>> m_SubNodes;
};

class Trie {
public:
    Trie() :m_Root(std::make_shared<TrieNode>(0)) {

    }

    void insert(string word) {
        auto node = m_Root;
        for (char cur : word) {
            if (node->m_SubNodes.count(cur) == 0) {
                node->m_SubNodes[cur] = make_shared<TrieNode>(cur);
            }
            node = node->m_SubNodes.at(cur);
        }
        node->m_IsWord = true;
    }

    bool search(string word) {
        auto node = m_Root;
        for (char cur : word) {
            if (node->m_SubNodes.count(cur) == 0) {
                return false;
            }
            node = node->m_SubNodes[cur];
        }
        return node->m_IsWord;
    }

    bool startsWith(string prefix) {
        auto node = m_Root;
        for (char cur : prefix) {
            if (node->m_SubNodes.count(cur) == 0) {
                return false;
            }
            node = node->m_SubNodes[cur];
        }
        return true;
    }

private:
    std::shared_ptr<TrieNode> m_Root;
    
};
