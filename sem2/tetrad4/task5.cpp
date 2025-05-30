#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Построение дерева
HuffmanNode* buildTree(const unordered_map<char, int>& freqMap) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    for (auto& pair : freqMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* newNode = new HuffmanNode('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

string encode(const string& text, const unordered_map<char, string>& huffmanCode) {
    string encoded;
    for (char ch : text) {
        encoded += huffmanCode.at(ch);
    }
    return encoded;
}


vector<pair<char, string>> getDict(const unordered_map<char, string>& huffmanCode) {
    vector<pair<char, string>> dict;
    for (auto& pair : huffmanCode) {
        dict.emplace_back(pair.first, pair.second);
    }
    return dict;
}

size_t estimateTotalSize(const string& encoded, const vector<pair<char, string>>& dict) {
    size_t totalBits = encoded.size(); 
    for (auto& entry : dict) {
        totalBits += 8 + 8 + entry.second.size();
    }

    return totalBits;
}

int main() {
    string text = "mireamireamirea";
    unordered_map<char, int> freqMap;

    for (char ch : text) {
        freqMap[ch]++;
    }

    HuffmanNode* root = buildTree(freqMap);

    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    string encoded = encode(text, huffmanCode);

    vector<pair<char, string>> dict = getDict(huffmanCode);

    size_t totalBits = estimateTotalSize(encoded, dict);

    cout << "Encoded string: " << encoded << endl;
    cout << "Encoded string size (bits): " << encoded.size() << endl;
    cout << "Dict size (bits): " << (totalBits - encoded.size()) << endl;
    cout << "Total data size (bits): " << totalBits << endl;

    return 0;
}