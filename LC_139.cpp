// Date: 2024-08-11
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd;

    TrieNode(): isEnd(false) {}
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insertWord(string& word){
        TrieNode* currentNode = root;
        for (char c: word){
            if (currentNode->children.find(c) == currentNode->children.end()){
                currentNode->children[c] = new TrieNode();
            }
            currentNode = currentNode->children[c];
        }
        currentNode->isEnd = true;
    }

    bool search(string& word, int start){
        TrieNode* currentNode = root;
        if (start == word.size() -1 && currentNode->children.find(word[start]) != currentNode->children.end() && currentNode->isEnd){
            return true;
        }
        for (int i = start; i < word.size(); i++){
            if (currentNode->isEnd){
                if (search(word, i)){
                    return true;
                }
            }
            if (currentNode->children.find(word[i]) == currentNode->children.end()){
                return false;
            }
            currentNode = currentNode->children[word[i]];
        }
        return currentNode->isEnd;
    }
};
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;

        for (string word: wordDict){
            trie.insertWord(word);
        }
        return trie.search(s, 0);
    }
};

int main() {
    vector<string> dict = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa","ba"};
    string word = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    Solution sln;
    bool result = sln.wordBreak(word, dict);
    cout << result << endl;
}