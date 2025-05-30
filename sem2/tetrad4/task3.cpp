#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    int prefixCount; // Количество слов, проходящих через этот узел
    TrieNode() : prefixCount(0) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
        node->prefixCount++;
    }
}

int countPrefixes(TrieNode* root, const string& word) {
    TrieNode* node = root;
    int count = 0;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return count;
        }
        node = node->children[index];
        count = node->prefixCount;
    }
    return count - 1;
}

string findWordWithMaxPrefixes(const vector<string>& words) {
    TrieNode* root = new TrieNode();
    for (const string& word : words) {
        insert(root, word);
    }

    string result;
    int maxPrefixes = -1;

    for (const string& word : words) {
        int currentPrefixes = countPrefixes(root, word);
        if (currentPrefixes > maxPrefixes || (currentPrefixes == maxPrefixes && word.length() > result.length())) {
            maxPrefixes = currentPrefixes;
            result = word;
        }
    }

    return result;
}

int main() {
    vector<string> words = {"a", "ab", "abc", "abcd", "abcdef", "bcd"};
    string result = findWordWithMaxPrefixes(words);
    cout << result << endl; 
    return 0;
}