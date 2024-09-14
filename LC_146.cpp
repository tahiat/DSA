// Date: 2024-09-11
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
using namespace std;


/*


Double LL: *(key,val) ===  (key1, val1) ======== (key2, val2) ===== *(key, val)
                                    \                   \
hash_map:                      [ key| *node ]      [key |  *node]


*/

struct Node {
    int val, key;
    Node* next;
    Node* prev;
    Node(int k, int v) {
        val = v;
        key = k;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
private: 
    unordered_map<int, Node*> hash_table;
    Node *left; //= new Node(0,  0);
    Node* right; // = new Node(0, 0);
    int cap;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    void insert(Node* node){
        Node* lst = right->prev;
        lst->next = node;
        node->next = right;
        right->prev = node;
        node->prev = lst;
    }

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
       // delete(node);
    }

    int get(int key) {
        if (hash_table.find(key) != hash_table.end()){
            // update the linked list
            remove(hash_table[key]);
            insert(hash_table[key]);
            return hash_table[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // check if key already exist
        if (hash_table.find(key) != hash_table.end()){
            remove(hash_table[key]);
            hash_table[key] = new Node(key, value);
            insert(hash_table[key]);
        }
        else {
            hash_table[key] = new Node(key, value);   
            insert(hash_table[key]); 
        }

        if (hash_table.size() > cap){
            Node* leastUsed = left->next;
            remove(leastUsed);
            hash_table.erase(leastUsed->key);
        }
    }
};


int main() {
    return 0;
}