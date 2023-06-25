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
       ListNode* next = NULL;
       ListNode* curr = head;
       while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
       }
       return prev;
}

void printMiddle(ListNode* head){
    ListNode*slow=head;
    ListNode*fast=head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->val;
}

bool checkPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* revHalf = slow->next;
    slow->next = NULL;

    revHalf = reverseLink(revHalf);

    slow->next = revHalf;

    slow = head;
    while(revHalf){
        if(slow->val != revHalf->val){
            return false;
        }
        slow=slow->next;
        revHalf=revHalf->next;
    }
    return true;
}

ListNode* sortLinkedList(ListNode* head){
        ListNode* newLink = new ListNode(-5001);
        // newLink->next = head;
        ListNode* temp = head;
        while(temp){
            cout<<"loop"<<endl;
            ListNode* createdNode = new ListNode(temp->val);
            ListNode* trav = newLink;
            if(!newLink->next){
                cout<<"if condition"<<endl<<endl;
                newLink->next = createdNode;
            }
            else{
                // cout<<"else condition: "<<createdNode->val<<" "<<trav->val <<endl;
                while(trav->next && createdNode->val > trav->val && createdNode->val >= trav->next->val){
                    cout<<trav->val<<" pos "<<createdNode->val<<endl;
                    trav = trav->next;
                }
                cout<<trav->val<<endl<<endl;
                trav->next = createdNode;
            }
            temp = temp->next;
        }
        return newLink->next;
     }
int main(){
    ListNode sol();
    ListNode* head = new ListNode(-1);
    ListNode* one = new ListNode(5);
    ListNode* two = new ListNode(3);
    ListNode* three = new ListNode(4);
    ListNode* four = new ListNode(0);
    // ListNode* five = new ListNode(10);
    // ListNode* six = new ListNode(55);
    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;
    // four->next = five;
    // five->next = six;
    printLinked(head);
    cout<<endl<<endl;
    // printMiddle(head);
    head = sortLinkedList(head);
    printLinked(head);

    return 0;
}