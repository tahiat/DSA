#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'swapNodes' function below.
 *
 * The function is expected to return a 2D_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY indexes
 *  2. INTEGER_ARRAY queries
 */
 
 struct Node {
     int data;
     Node *left, *right;
     
     Node(int x): data(x), left(NULL), right(NULL) {}
 };
 
void inorderTraversla(Node* node, vector<int>& nodes){
    if (!node){
        return;
    }
    
    inorderTraversla(node->left, nodes);
    nodes.push_back(node->data);
    inorderTraversla(node->right, nodes);
}

void swapUtils(Node* node, int level, int& k){
    if (!node || (!node->left && !node->right)){
        return;
    }
    
    if (level % k == 0){
        swap(node->left, node->right);
    }
    
    swapUtils(node->left, level+1, k);
    swapUtils(node->right, level+1, k);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node *root = new Node(1);
    queue<Node*> Q;
    Q.push(root);
    
    for (int i = 0; i < indexes.size(); i++){
        Node* cur = Q.front();
        Q.pop();
        
        if (indexes[i][0] != -1){
            Node* l = new Node(indexes[i][0]);
            cur->left = l;
            Q.push(l);
        }
        
        if (indexes[i][1] != -1){
            Node* r = new Node(indexes[i][1]);
            cur->right = r;
            Q.push(r);
        }
    }
    vector<vector<int>> ans;
    
    for (int i = 0; i < queries.size(); i++){
        vector<int> result;   
        swapUtils(root, 1, queries[i]);
        inorderTraversla(root, result);
        ans.push_back(result);
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> indexes(n);

    for (int i = 0; i < n; i++) {
        indexes[i].resize(2);

        string indexes_row_temp_temp;
        getline(cin, indexes_row_temp_temp);

        vector<string> indexes_row_temp = split(rtrim(indexes_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int indexes_row_item = stoi(indexes_row_temp[j]);

            indexes[i][j] = indexes_row_item;
        }
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
