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

/**
 * Definition for singly-linked list.*/
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultHead = new ListNode();
        ListNode* resultTail = resultHead;

        int sum = 0;
        int carry = 0;
        while (l1 && l2){
            sum = l1->val + l2->val + carry;

            resultTail->next = new ListNode(sum%10);
            resultTail = resultTail->next;
        
            carry = sum /10;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1){
            sum = l1->val + carry;

            resultTail->next = new ListNode(sum%10);
            resultTail = resultTail->next;

            carry = sum /10;
            l1 = l1->next;
        }

        while (l2){
            sum = l2->val + carry;

            resultTail->next = new ListNode(sum%10);
            resultTail = resultTail->next;

            carry = sum /10;
            l2 = l2->next;
        }
        if (carry){
            resultTail->next = new ListNode(carry);
        }

        return resultHead->next;
    }
};

int main() {
    Solution sln;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(4);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(6);
    cout << "result is " << sln.addTwoNumbers(l1,l2) << endl;
}