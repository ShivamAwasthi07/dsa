#include <iostream>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int val){
        this->data = val;
        this->next = NULL;
    }
};

ListNode* createNode(int val){
    ListNode * node = new ListNode(val);
    return node;
}

void printLinkedList(ListNode *& head){
    ListNode* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void insertAtHead(ListNode *& head, int val){
    ListNode* newNode = createNode(val);
    newNode->next = head;
    head = newNode;
}

void insertAtLast(ListNode *& head, int val){
    ListNode* newNode = createNode(val);
    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertAtLastT(ListNode *& head, ListNode *& node){
    // ListNode* newNode = createNode(val);
    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
}

void reverse(ListNode*& head, ListNode* curr, ListNode* prev){
    if(curr == NULL) {
        head = prev;
        return;
    }
    ListNode* forw = curr->next;
    reverse(head, forw, curr);
    curr->next = prev;
}

ListNode* revRecursion(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;

    reverse(head, curr, prev);
    return head;
}

ListNode* sumLinkedList(ListNode* first, ListNode* second){
    int carry=0;
    ListNode* temp = createNode(0);
    while(first!=NULL && second!=NULL){
        int sum = (first->data+second->data+carry);
        int carry = sum/10;
        ListNode* temp1 = createNode(sum%10);
        insertAtLastT(temp, temp1);
    }

    // cout<<sum->data;
    // printLinkedList(sum->next);
}

int main(){

    ListNode* first = new ListNode(1);
    insertAtLast(first, 5); //15

    ListNode* second = new ListNode(2);
    insertAtLast(second, 1); //21

    printLinkedList(first);
    cout<<endl;
    printLinkedList(second);
    cout<<endl;

    ListNode* firstRev = revRecursion(first); 
    ListNode* secondRev = revRecursion(second); 
    printLinkedList(firstRev);
    cout<<endl;
    printLinkedList(secondRev);
    cout<<endl;

    sumLinkedList(firstRev, secondRev);


    return 0;
}