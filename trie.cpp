#include<iostream>

using namespace std;

struct Node {
    bool end;
    Node *next[26];

    Node () {
        end = false;
        for (int i = 0; i< 26; i++){
            next[i] = NULL;
        }
    }
} *root;


void insert(string str){
    Node *current = root;

    for (int i = 0; i< str.size(); i++){
        int id = str.at(i) - 'a';
        if (current->next[id] == NULL){
            current->next[id] = new Node();
        }
        current = current->next[id];
    }
    current->end = true;
}

bool search(string str){
    Node *current = root;

    for(int i = 0; i<str.size(); i++){
        int id = str[i] - 'a';
        if (current->next[id] == NULL){
            return false;
        }
        current = current->next[id];
    }
    return current->end;
}

int main () {
    root = new Node();

    insert("Hello");
    insert("Tamima");
    insert("Touhid");

    cout<< "Tahiatul --> " << search("Tahiatul")<<endl;
    cout<< "Tamima --> " << search("Tamima") << endl;
    cout<< "tamima --> " << search("tamima") << endl;
    cout<< "zaman  ->> "<< search ("zaman") << endl;

}