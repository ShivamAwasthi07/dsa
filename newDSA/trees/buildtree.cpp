#include <iostream>
#include <queue>
using namespace std;

class node{
    public: 
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }

}; 

void inorderTrav(node* root){
    if(root == NULL){
        return;
    }
    inorderTrav(root->left);
    cout<<root->data<<" ";
    inorderTrav(root->right);
}

node * buildTree(node* root){
    int val;
    cout<<"enter the data: ";
    cin>>val;
    root = new node(val);
    if(val == -1){
        return NULL;
    }

    cout<<"enter the data in left: ";
    root->left = buildTree(root->left);
    cout<<"enter the data in right: ";
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTrav(node* root){
    cout<<endl;
    cout<<endl;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node*temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<<temp->data<<" ";

            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
    }
}

int main(){

    node* root = NULL;
    root = buildTree(root);
    // cout<<root->data;
    // inorderTrav(root);
    cout<<endl;
    cout<<endl;
    levelOrderTrav(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1