// Date: 2024-07-22
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<set>

using namespace std;


class Trie{
public:
    vector<Trie*> children;
    bool isWord;
    Trie() {
        children = vector<Trie*> (26, NULL);
        isWord = false;
    }
};
class Solution {
private:
Trie* root;
public:
    void insertWord(string word){
        Trie* cur = root;
        int idx;
        for (int i = 0; i<word.size(); i++){
            idx = word[i] - 'a';
            if (cur->children[idx] == NULL){
                cur->children[idx] = new Trie();
            }
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        root = new Trie();

        int r = board.size();
        int c = board[0].size();
        set<string> result_set;
     
        for (auto word: words){
            insertWord(word);
        }

        Trie* current = root;

        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                string s = "";
                dfs(board, i, j, r, c, root, s, result_set);      
            }
        }
        vector<string> result_vector(result_set.begin(), result_set.end());
        return result_vector;
    }

    void dfs(vector<vector<char>>& board, int m, int n, int r, int c, Trie* node, string cur_word, set<string>& res) {
        if (m < 0 || m >= r || n < 0 || n >= c || board[m][n] == '#' || node->children[board[m][n]-'a'] == NULL) {
            return ;
        }

        char original = board[m][n];
        node = node->children[board[m][n]-'a'];
        cur_word += original;
        if (node->isWord) {
            res.insert(cur_word);
        }
        
    
        board[m][n] = '#'; // make that visited;
        dfs(board, m-1,n, r, c, node, cur_word , res);
        dfs(board, m+1,n, r, c, node, cur_word, res);
        dfs(board, m,n-1, r, c, node, cur_word,res);
        dfs(board, m,n+1, r, c, node, cur_word, res);
        board[m][n] = original;

        return;
    }

};


int main() {
    Solution s;

    vector<vector<char>> board 
    { 
        {'o','a','a','n'},  
        {'e','t','a','e'},  
        {'i','h','k','r'},
        {'i','f','l','v'}  
    };
    vector<string> words {"oath","pea","eat","rain"};

    auto result = s.findWords(board, words);

    return 0;
}