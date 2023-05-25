#include <iostream>
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

int heightOfTree(node* root){
    int count =0;

    if(root == NULL){
        return 0;
    }

    count = max(heightOfTree(root->left), heightOfTree(root->right))+1;

    return count;
}

int main(){
    node* root = NULL;
    root = buildTree(root);

    int x = heightOfTree(root);
       cout<<endl;
    cout<<endl;
    cout<<x;
    return 0;
}