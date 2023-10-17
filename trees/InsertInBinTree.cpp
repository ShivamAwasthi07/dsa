// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;

// class node{
//     public:
//     int val;
//     node* left;
//     node* right;
//     node(int val){
//         this->val = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// void levelOrder(node* root){
//         queue <node*> q;
//         if(!root){
//             return;
//         }
//         q.push(root);
//         q.push(NULL);
//         while(!q.empty()){
//             node* front = q.front();
//             q.pop();
//             if(front == NULL){
//                 cout<<endl;
//                 if(!q.empty()){
//                     q.push(NULL);
//                 }
//             }
//             else{
//                 if(front->left){
//                     q.push(front->left);
//                 }
//                 if(front->right){
//                     q.push(front->right);
//                 }
//                 cout<<front->val<<" ";
//             }
//         }

//     }

// node* buildTree(node* root){
//     cout<<"enter the data"<<endl;
//     int val;
//     cin>>val;
//     root = new node(val);
//     if(val == -1){
//         return NULL;
//     }
//     cout<<"LEFT ";
//     root->left = buildTree(root->left);
//     cout<<"RIGHT ";
//     root->right = buildTree(root->right);
// }

// int heightBinaryTrees(node* root){
//     if(root == NULL){
//         return 0;
//     }
//     int left = heightBinaryTrees(root->left);
//     int right = heightBinaryTrees(root->right);

//     return max(left, right)+1;
// }

// int main(){
//     node* root;
//     root = buildTree(root);
//     levelOrder(root);
//     cout<<heightBinaryTrees(root);
//     return 0;
// }

// // 10 20 30 -1 -1 25 -1 -1 99 65 -1 -1 88 -1 -1
#include <iostream>
#include <vector>
using namespace std;

void p(vector<int> v){
    for(int i: v){
        cout<<i<<" ";
    }
}
int main(){
    // cout<<"sssss";
    // vector<int>v;
    // // v.push_back(5);
    // cout << v[0] << endl;
    vector<int> v;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    p(v);

    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    return 0;

}