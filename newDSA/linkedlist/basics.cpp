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

ListNode* reverseLinkedList(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forw = NULL;


    while(curr!=NULL){
        cout<<"curr is"<<curr->data<<endl;
        forw = curr->next;
        curr->next = prev;
        prev=curr;
        curr = forw;
    }

    return prev;
}

void reverse(ListNode*&head, ListNode* curr, ListNode* prev){
    if(curr==NULL){
        head = prev;
        return;
    }

    ListNode* forw = curr->next;
    reverse(head, forw, curr);
    curr->next = prev;
}

ListNode* revRec(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    reverse(head, curr, prev);
    return head;

}

ListNode* middleOfLL(ListNode* head){
    if(head==NULL){
        cout<<"encountered if";
        return NULL;
    }
    else if(head->next == NULL){
        cout<<"encountered else if";
        return head;
    }
    else{
        ListNode* slow = head;
        ListNode* fast = head;
        cout<<"encountered else";
        while(fast!=NULL && fast->next!=NULL){
            cout<<"slow data: "<<slow->data<<endl;
            cout<<"fast data: "<<fast->data<<endl;
            slow= slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
}

void mergeLL(ListNode*&first, ListNode*&second){
    ListNode* curr1 = first;
    ListNode* next1 = first->next;

    ListNode* curr2 = second;
    ListNode* next2 = second->next;

    while(curr1 != NULL && curr2 != NULL){
        if((curr1->data <= curr2->data) && (next1->data >= curr2->data)){
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else{
            curr1 = next1;
            curr2 = next2;

            next1 = next1->next;
            next2 = next2->next;
        }
    }
    
    printLinkedList(curr1);
}

int main(){
    ListNode* first = new ListNode(1);
    ListNode* second = new ListNode(2);
    insertAtLast(first, 5);
    insertAtLast(first, 10);
    insertAtLast(first, 15);
    insertAtLast(first, 20);
    insertAtLast(second, 9);
    insertAtLast(second, 12);
    insertAtLast(second, 16);
    insertAtLast(second, 18);
    insertAtLast(second, 21);
    mergeLL(first, second);
    // ListNode* rev = middleOfLL(head);
    // cout<<rev->data;
    return 0;
}