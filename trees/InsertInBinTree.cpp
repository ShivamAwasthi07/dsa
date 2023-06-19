// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
//     // int val;
//     // TreeNode* left;
//     // TreeNode* right;
//     // TreeNode(int v){
//     //     this->val = v;
//     //     this->right=NULL;
//     //     this->left=NULL;
//     // }

// class Solution {
// public:
//     void insert(TreeNode* &root, int val){
//         TreeNode* temp = root;
//         if(temp->val < val && temp->right != NULL){
//             insert(temp->right, val);
//         }
//         if(temp->val > val && temp->left != NULL){
//             insert(temp->left, val);
//         }
//         if(temp->left == NULL && temp->right == NULL){
//             TreeNode* t = new TreeNode(val);
//             if(temp->val > val){
//                 temp->left = t;
//             }
//             else if(temp->val < val){
//                 temp->right = t;
//             }
//             return;
//         }
//         return;

//     }
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//            insert(root, val);
//            return root;
//     }
// };

// int main(){
//     // Solution sol;
//     return 0;
// }