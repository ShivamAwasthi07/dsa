#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int num){
        this->left=NULL;
        this->right=NULL;
        this->val=num;
    }

};

Node* BuildBinaryTree(Node* root){
    cout<<"enter data:"<<endl;
    int val;
    cin>>val;
    root = new Node(val);
    if(val == -1){
        return NULL;
    }
    cout<<"left data of "<<val<<": "<<endl;
    root->left = BuildBinaryTree(root->left);
    cout<<"right data of "<<val<<": "<<endl;
    root->right = BuildBinaryTree(root->right);
}

void inorder(Node* root){
    if(!root){
        return;
    }
    cout<<root->val<<" ";
    inorder(root->left);
    inorder(root->right);
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        vector<int> v;
        Node* temp = NULL;
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp == NULL){
                ans.push_back(v);
                v.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                v.push_back(temp->val);
            }
        }
        return ans;
    }
};



int main(){
    Node* root;
    root = BuildBinaryTree(root);
    inorder(root);
    Solution sol;
    vector<vector<int>> v = sol.levelOrder(root);

cout<<endl<<endl;
    for(vector<int> a: v){
        for(int x : a){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// 10 20 30 -1 -1 25 -1 -1 99 65 -1 -1 88 -1 -1