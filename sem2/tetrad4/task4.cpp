#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

// Узел дерева Хаффмана
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}//список инициализации
};

// Компаратор min-heap
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {//переопределение ()
        return a->freq > b->freq;
    }
};

class Huffman {
private:
    HuffmanNode* root;
    unordered_map<char, string> codes;
    unordered_map<string, char> reverseCodes;

public:
    Huffman() : root(nullptr) {}

    ~Huffman() {
        freeTree(root);
    }

    void buildTree(const unordered_map<char, int>& freqMap) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

        for (auto& pair : freqMap)
            pq.push(new HuffmanNode(pair.first, pair.second));

        while (pq.size() > 1) {
            HuffmanNode* left = pq.top(); pq.pop();
            HuffmanNode* right = pq.top(); pq.pop();

            HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            pq.push(merged);
        }

        root = pq.top();
        generateCodes(root, "");
    }
    unordered_map<char, int> buildFrequencyMap(const string& text) {
        unordered_map<char, int> freqMap;
        for (char ch : text)
            freqMap[ch]++;
        return freqMap;
    }


    string encode(const string& text) {
        stringstream encoded;
        for (char ch : text)
            encoded << codes[ch];
        return encoded.str();
    }


    string decode(const string& encodedText) {
        string decoded;
        HuffmanNode* node = root;
        for (char bit : encodedText) {
            if (bit == '0') node = node->left;
            else node = node->right;

            if (!node->left && !node->right) {
                decoded += node->ch;
                node = root;
            }
        }
        return decoded;
    }

    double compressionRatio(const string& original, const string& encoded) {
        int originalBits = original.length() * 8;
        int compressedBits = encoded.length();
        return static_cast<double>(originalBits) / compressedBits;
    }

    void printCodes() {
        for (auto& pair : codes)
            cout << pair.first << ": " << pair.second << endl;
    }

private:
    void generateCodes(HuffmanNode* node, const string& currentCode) {
        if (!node) return;

        if (!node->left && !node->right) {
            codes[node->ch] = currentCode;
            reverseCodes[currentCode] = node->ch;
        }

        generateCodes(node->left, currentCode + "0");
        generateCodes(node->right, currentCode + "1");
    }

    void freeTree(HuffmanNode* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
};



int main() {
    Huffman huffman;
    string text = "hello world";
    

    auto freqMap = huffman.buildFrequencyMap(text);
    huffman.buildTree(freqMap);
    

    string encoded = huffman.encode(text);
    string decoded = huffman.decode(encoded);
    

    cout << "Original: " << text << endl;
    cout << "Encoded: " << encoded << endl;
    cout << "Decoded: " << decoded << endl;
    cout << "Compression ratio: " << huffman.compressionRatio(text, encoded) << endl;
    
    return 0;
}