// Date: 2024-07-21
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        return join(res, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }

    void dfsSerialize(TreeNode *node, vector<string>& res){
        if (!node){
            res.push_back("N");
            return;
        }
        res.push_back(to_string(node->val));
        dfsSerialize(node->left, res);
        dfsSerialize(node->right, res);
    }

    string join(vector<string>& s, string delim){
        ostringstream res;
        for(int i = 0; i< s.size(); i++){
            res << s[i];
            if (i != s.size() - 1){
                res << delim;
            }
        }
        return res.str();
    }
    vector<string> split(string s, char delim){
        istringstream ss(s);
        vector<string> res;
        string item;
        while (getline(ss, item, delim)){
            res.push_back(item);
        }
        return res;
    }
};

int main() {
    Codec s;
    vector<string> d = {"1", "3","4","5"};
    cout << s.join(d, ",");
    auto r = s.split("1,3,4,5", ',');

    cout << "h";
} 