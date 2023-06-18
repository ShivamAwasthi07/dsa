#include <iostream>
#include <bits/stdc++.h>
using namespace std;



class Node{
    public:
    Node* next;
    int data;
     Node(int val){
        this->data = val;
        this->next = NULL;
     }
};

int getDecimalValue(Node* head) {
        int finalAns = 0;
        while(head){
            finalAns= finalAns*2+head->data;
            cout<<head->data;
            head = head->next;
            cout<<" "<<finalAns<<endl;
        }
        // finalAns+= finalAns*2+head->val;
        return finalAns;
    }

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"NULL"<<endl;

}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    Node* rev(Node *head){
        if(head->next == NULL || head == NULL){
            return head;
        }
        Node* h = NULL;
        Node* ptr = rev(head->next);
        ptr = head;
    }
    Node* reverseLinked(Node* head){
        Node* h = NULL;
        rev(head->next);
        printList(head);
        // return head; 
    }

    Node* mergeNodes(Node* head) {
        Node* ans = new Node(-1);
        Node* ptr = ans;
        head = head->next;
        int sum=0;
        while(head){
            if(head->data){
                sum+=head->data;
            }
            else{
                Node* p = new Node(sum);
                ptr->next = p;
                ans=ptr;
                sum=0;
            }
                head = head->next;
        }
        return ans->next;
        
    }
};

void mergeList(Node* head1, Node* head2){
    while(head1 && head2){
        if(head1->data <= head2->data){
            cout<<head1->data<<" -> ";
            head1 = head1->next;
        }
        else{
            cout<<head2->data<<" -> ";
            head2 = head2->next;
        }
    }
    while(head1){
        cout<<head1->data<<" -> ";
        head1 = head1->next;
    }
    while(head2){
        cout<<head2->data<<" -> ";
        head2 = head2->next;
    }
}

Node * insertionStart(Node * head, int val){
    Node* temp = head;
    Node* ptr = new Node(val);
    ptr->next = head;
    head = ptr;
    return ptr;
}

Node * insertionLast(Node * head, int val){
    Node* temp = head;
    Node* ptr = new Node(val);
    while(head->next){
        head = head->next;
    }
    head->next = ptr;
    return temp;
}

Node * insertionIndex(Node * head, int val, int i){
    Node* temp = head;
    Node* ptr = new Node(val);
    int index=0;
    while(index < i-1){
        head = head->next;
        index++;
    }
    if(head){
        ptr->next = head->next;
        head->next = ptr;
        return temp;
    }
    else{
        cout<<"Not a Valid Index!!!";
    }
}

Node * delFirst(Node* head){
    Node* temp = head;
    head = head->next;
    temp->next=NULL;
    free(temp);
    return head;
}

Node * AddLinkedList(Node* first, Node* second){
    if(first == NULL){
        return second;
    }
    if(second == NULL){
        return first;
    }

    Node* result = new Node(-1);
    Node* ans = new Node(0);
    result->next =ans;

    Node* f = first;
    Node* s = second;
    int carry=0,a=0,b=0;
    while(f || s){
        if(f){
            a=f->data;
        }
        else{
            a=0;
        }
        if(s){
            b=s->data;
        }
        else{
            b=0;
        }
        cout<<(a+b+carry)%10<<" ";
        cout<<(a+b+carry)/10<<endl;
        Node * node = new Node((a+b+carry)%10);
        // result->data= (a+b+carry)%10;
        carry = (a+b+carry)/10;
        ans->next = node;
        ans = ans->next;
        if(f){
            f=f->next;
        }
        if(s){
            s=s->next;
        }
        
    }
    if(carry != 0){
        Node* n = new Node(carry);
        ans->next=n;
    }
    return result;

}

int main(){
    Node* list = new Node(8);
    Node* list1 = new Node(6);
    Node* list2 = new Node(9);

    Node* list3 = new Node(9);
    Node* list4 = new Node(9);
    // Node* list5 = new Node(9);
    // Node* list5 = new Node(1);
    // Node* list3 = new Node(12);
    // Node* list4 = new Node(15);
    // Node* list5 = new Node(17);
    list->next=list1;
    list1->next=list2;
    // list2->next = list3;
    list3->next = list4;
    // list4->next = list5;
    // list4->next = list5;
    printList(list);
    printList(list3);
    // list = delFirst(list);
    list = AddLinkedList(list, list3);
    printList(list->next->next);
    return 0;
}