// Date: 2024-07-25
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
private:
//set<int> visit;
vector<Node*> storage;    
public:
    Node* cloneF(Node* node){
        if (storage[node->val] != NULL){
            return storage[node->val];
        }

        Node* clonenode = new Node(node->val);
        storage[node->val] = clonenode;
        for (Node* adj: node->neighbors){
            Node* adjnode = cloneF(adj);
            clonenode->neighbors.push_back(adjnode);
        }
        return clonenode;
    }
    Node* cloneGraph(Node* node) {
        //visit.clear();
        storage = vector<Node*>(101, NULL);
        Node* newnode = cloneF(node);
        return newnode;
    }
};

int main() {
    Node* n2 = new Node(2);
    Node* n1 = new Node(1);
    Node* n3 = new Node(3);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n2);
    Solution sl;
    sl.cloneGraph(n1);
}