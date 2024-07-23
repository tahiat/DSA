// Date: 2024-07-20
// Description: 

#include <iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int kk = 0;
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root && root->left){
           kthSmallest(root->left, k);
        }
        k--;
        if (k==0){
            return root->val;
        }
        if (root && root->right){
            kthSmallest(root->right, k);
        }
        return 0;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<vector<TreeNode*>> q;
        if (root != NULL){
            q.push({root});
        }       
        while (!q.empty()){
            vector<TreeNode*> temp = q.front();
            q.pop();
            vector<TreeNode*> input;
            vector<int> re;
            for (int p = 0; p<temp.size(); p++){
                TreeNode *t = temp[p];
                re.push_back(t->val);
                if (t->left != NULL){
                    input.push_back(t->left);
                }
                if (t->right != NULL){
                    input.push_back(t->right);
                }
            }
            if (re.size() > 0){
                result.push_back(re);
            }
            if (input.size()>0){
                q.push(input);
            }
            
        }
        return result;
    }
};

int main() {
    /*TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20));
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    Solution st;
    st.levelOrder(root);
    */
    TreeNode *root = new TreeNode(4, new TreeNode(3, new TreeNode(2), nullptr), new TreeNode(4));
    //root->right->left = new TreeNode(15);
    //root->right->right = new TreeNode(7);
    Solution st;
    st.kthSmallest(root,4);
}  