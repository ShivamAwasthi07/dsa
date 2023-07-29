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

class Solution{
     public:
     vector<int> pre;
     vector<int> inorder;
     vector<int> post;

     stack<pair<Node*, int>> st;

     vector<vector<int>> func(Node* given){
        st.push({given, 1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();

            cout<<it.first->data<<" "<<it.second<<endl<<endl;

            if(it.second == 1){
                pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->left != NULL){
                    st.push({it.first->left, 1});
                }  
            }
            else if(it.second == 2){
                inorder.push_back(it.first->data);
                it.second++;
                st.push(it);
                if(it.first->right != NULL){
                    st.push({it.first->right, 1});
                }  
            }
            else{
                post.push_back(it.first->data);
            }
        }
        return {pre, inorder, post};
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

void inorder(Node * root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int maxHeight(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = maxHeight(root->left);
    int right = maxHeight(root->right);
    return max(left, right)+1;
}


pair<bool, int> isBalanced(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    // int left = isBalanced(root->left);
    // int right = maxHeight(root->right);

    // int diff = abs(left-right);
    // if(diff>1){
    //     return false;
    // }

    pair<bool, int> isLeftBalanced = isBalanced(root->left); 
    pair<bool, int> isRightBalanced = isBalanced(root->right); 

    bool leftAns = isLeftBalanced.first;
    bool rightAns = isRightBalanced.first;

    bool finalResultBool = leftAns && rightAns && abs(isLeftBalanced.second-isRightBalanced.second) <= 1;
    int maxHeight = max(isLeftBalanced.second, isRightBalanced.second)+1;
    return {finalResultBool, maxHeight};
}

void printTree(Node* root){
    if(!root){
        return;
    }
    printTree(root->left);
    cout<<root->data<<" ";
}
void topOfBinaryTree(Node* root){
    Node* temp = root;
    printTree(root);
    while(temp){
        temp = temp->right;
        cout<<temp->data<<" ";
    }
}

// int maxHeight2(Node* root, int &diameter){
//     if(root == NULL){
//         return 0;
//     }
//     int left = maxHeight2(root->left, diameter);
//     int right = maxHeight2(root->right, diameter);
//     diameter = max(diameter, left+right);
//     return max(left, right)+1;
// }

// int solve_diameter(Node* root){
//     int diameter = 0;
//     int ans;
//     ans = maxHeight2(root, diameter);
//     return ans;
// }

// pair <int, int> solve_diameter2(Node* root, int &ans){
    
//     if(!root){
//         return make_pair(0, ans);
//     }

//     pair<int, int> left = solve_diameter2(root->left, ans);
//     pair<int, int> right = solve_diameter2(root->right, ans);
//     ans = max((left.second+right.second),ans);

//     // solve_diameter(root->left, ans);
//     // solve_diameter(root->right, ans);

// }

// int diameterOfTheTree(Node* root){
    // int ans = solve_diameter(root);
    // return ans;
// }
void diameterOfTheTree(Node* root, int &dia){
    if(!root){
        return;  
    }

    int left = maxHeight(root->left);
    int right = maxHeight(root->right);

    dia = max(dia, left+right);

    diameterOfTheTree(root->left, dia);
    diameterOfTheTree(root->right, dia);

}

int main(){
    Solution sol;
    Node* root = NULL;
    root = buildTree(root);
    // inorder(root);
    // Solution sol;
    // cout<<isBalanced(root).first<<" "<<isBalanced(root).second;

    // topOfBinaryTree(root);
    // vector<vector<int>> ans = sol.func(root);
    int dia=0;
    diameterOfTheTree(root, dia);
    cout<<dia;
    // for(vector<int> elem : ans){
    //     for(int item : elem){
    //         cout<<item<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}

// 5 10 15 -1 -1 20 -1 -1 25 30 -1 -1 35 -1 -1 
// 1 2 -1 -1 3 4 5 9 -1 -1 -1 -1 6 -1 7 -1 8 -1 -1 