#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int num){
        this->val = num;
        this->next = NULL;
    }
   
     ListNode* addNum(ListNode* one, ListNode* two){

     }
};

void printLinked(ListNode* head){
    ListNode* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

 ListNode* reverseLink(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* q = NULL;
        while(curr){
            q = curr->next;
            curr->next = prev;
            prev = curr;
            curr = q;
        }
        
        return prev;
    }

int main(){
    // Solution sol;
    ListNode* head = new ListNode(5);
    ListNode* one = new ListNode(10);
    ListNode* two = new ListNode(15);
    ListNode* three = new ListNode(20);
    ListNode* four = new ListNode(25);
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    printLinked(head);
    head = reverseLink(head);
    printLinked(head);

    return 0;
}