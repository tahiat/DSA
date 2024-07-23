// Date: 2024-07-15
// Description: 

#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head==NULL)return;
        ListNode* middle, *fast, *slow;
        
        fast = head;
        slow = head;
        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        middle = slow->next;
        slow->next = NULL; // break the link
        // reverse the LL from middle to end
        ListNode *prev = NULL;
        while(middle){
            fast = middle->next;
            middle->next = prev;
            prev = middle;
            middle = fast;
        }
        //last node is prev
        //head;
        slow = head;
        fast = prev;
        int i = 0;
        ListNode *temp;
        while(slow && fast){
            middle = slow->next;
            slow->next = fast;
            prev = fast->next;
            fast->next = middle;
            slow = middle;
            fast = prev;
        }
    }
};

int main() {
    ListNode *head=new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sl;

    sl.reorderList(head);
}