#include <iostream>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
TrieNode* root = new TrieNode();

void insert(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

bool search(const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

int countWords(TrieNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int count = 0;
    if (node->isEndOfWord) {
        count++;
    }
    for (int i = 0; i < 26; i++) {
        count += countWords(node->children[i]);
    }
    return count;
}

int NumberOfWordsStartsWith(const string& pref) {
    TrieNode* node = root;
    for (char ch : pref) {
        int index = ch - 'a';
        if (node->children[index] == nullptr) {
            return 0;
        }
        node = node->children[index];
    }
    return countWords(node);
}

int main() {
    insert("apple");
    insert("app");
    insert("application");
    insert("banana");
    insert("ball");
    insert("bat");
    insert("batman");

    cout << "Search 'app': " << (search("app") ? "Found" : "Not found") << endl;
    cout << "Search 'apple': " << (search("apple") ? "Found" : "Not found") << endl;
    cout << "Search 'batman': " << (search("batman") ? "Found" : "Not found") << endl;
    cout << "Search 'batbat': " << (search("batbat") ? "Found" : "Not found") << endl;


    cout << "\nWords starting with 'app': " << NumberOfWordsStartsWith("app") << endl;
    cout << "Words starting with 'ba': " << NumberOfWordsStartsWith("ba") << endl;
    cout << "Words starting with 'bat': " << NumberOfWordsStartsWith("bat") << endl;
    cout << "Words starting with 'banana': " << NumberOfWordsStartsWith("banana") << endl;
    cout << "Words starting with 'xyz': " << NumberOfWordsStartsWith("xyz") << endl;

    return 0;
}