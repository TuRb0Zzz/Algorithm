#include <iostream>
using namespace std;

struct TrieNode{
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode():isEndOfWord(false){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
TrieNode* root = new TrieNode();

void insert(const string& word){
    TrieNode* node = root;
    for(char ch:word){
        int index = ch - 'a';
        if(node->children[index]==nullptr){
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord=true;
}

bool search(const string& word){
    TrieNode* node = root;
    for(char ch:word){
        int index = ch - 'a';
        if(node->children[index]==nullptr){
            return false;
        }
        node = node->children[index];
    }
    return node->isEndOfWord;
}

int countWords(TrieNode* node) {//рекурсивная функция подсчёта "конца слов"
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

int NumberOfWordsStartsWith(const string& pref){//переходит по префиксу и считает окончания слов после
    if(!search(pref)){return 0;}
    TrieNode* node = root;
    for(char ch:pref){
        int index = ch - 'a';
        node = node->children[index];
    }
    return countWords(node);
}

bool hasChildren(TrieNode* node) {
    for (int i = 0; i < 26; i++) {
        if (node->children[i] != nullptr) {
            return true;
        }
    }
    return false;
}

bool deleteWord(TrieNode* node, const string& word, int depth = 0) {
    if (node == nullptr) {
        return false;
    }

    if (depth == word.size()) {
        if (node->isEndOfWord) {
            node->isEndOfWord = false;
        }

        if (!hasChildren(node)) {
            delete node;
            return true;
        }
        return false;
    }

    int index = word[depth] - 'a';
    bool shouldDeleteChild = deleteWord(node->children[index], word, depth + 1);

    if (shouldDeleteChild) {
        node->children[index] = nullptr;
    }

    if (!node->isEndOfWord && !hasChildren(node)) {
        delete node;
        return true;
    }

    return false;
}

int main() {
    insert("apple");

    cout << "Search 'apple': " << (search("apple") ? "Found" : "Not found") << endl;
    
    deleteWord(root, "apple");
    
    cout << "Search 'apple': " << (search("apple") ? "Found" : "Not found") << endl;
    
    return 0;
}
