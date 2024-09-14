// Date: 2024-09-11
// Description: 

#include <iostream>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int main() {
    return 0;
}

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copy(Node* cur, unordered_map<Node*, Node*>& hash_map){
        if (cur == NULL){
            return cur;
        }


        Node* next = copy(cur->next, hash_map); // this will pass the copied version of next node

        Node* cur_copy;// = new Node(cur->val);
        if (hash_map.find(cur) != hash_map.end()){
            cur_copy =  hash_map[cur];  
        }
        else {
            cur_copy = new Node(cur->val);
            hash_map[cur] = cur_copy;    
        }
        
       
        cur_copy->next = next;   // next should always be the copied node.


        if (cur->random != NULL){
            Node* random_copy;
            if (hash_map.find(cur->random) != hash_map.end()){
                random_copy =  hash_map[cur->random];  
            }
            else {
                random_copy = new Node(cur->random->val);
                hash_map[cur->random] = random_copy;    
            } 
            //random_copy = new Node(cur->random->val);
            hash_map[cur->random] = random_copy;
            cur_copy->random = random_copy;
        }

        //delete(cur); //delete later

        return cur_copy;
    }

    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hash_map;
        return copy(head, hash_map);
    }
};