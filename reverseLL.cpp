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

struct Node{
    int val;
    Node* next;
    Node(int v){val = v; next = NULL;}
    Node(int v, Node* ne){
        val = v;
        next = ne;
    }
};

Node* reverse(Node* head){
    Node *prev = NULL, *cur = head;

    while(cur){
        Node* temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }

    return prev;
}

Node* recursiveReverse(Node* head){
    if (head->next == NULL) return head;

    Node* newHead = recursiveReverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead; 
}


void printLL(Node *head){
    Node *cur = head;
    while (cur){
        cout << cur->val << ", ";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    Node *head = new Node(1, new Node(2, new Node(3, new Node(4, NULL))));

    //Node* newHead = reverse(head);
    Node* newHead = recursiveReverse(head);
    printLL(newHead);
}