#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node * root){
    cout<<"data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter left";
    root->left = buildTree(root->left);
    cout<<"Enter right";
    root->right = buildTree(root->right);

    return root;
}

class Solution{
     public:
     void solve_left(Node* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }
        if(level > ans.size()){
            ans.push_back(root->data);
        }
        solve_left(root->left, ans, level+1);
        solve_left(root->right, ans, level+1);
     }
     void solve_right(Node* root, vector<int> &ans, int level){
        if(root == NULL){
            return;
        }
        if(level > ans.size()){
            ans.push_back(root->data);
        }
        solve_right(root->right, ans, level+1);
        solve_right(root->left, ans, level+1);
     }
     vector<vector<int>> sidesOfTheTree(Node* root){
        vector<int> ans_left;
        vector<int> ans_right;
        int level=1;
        solve_right(root, ans_right, level);
        solve_left(root, ans_left, level);
        return {ans_left, ans_right};
     }
     
};

int main(){
     Solution sol;
    Node* root = NULL;
    root = buildTree(root);
    vector<vector<int>> v = sol.sidesOfTheTree(root);
    for(auto i : v){
        cout<<"==> ";
        for(int a : i){
            cout<<a<<" ";
        }
    }
    return 0;
}

// 10 5 3 2 -1 -1 4 -1 100 -1 -1 6 -1 9 -1 -1 13 11 -1 -1 19 -1 -1