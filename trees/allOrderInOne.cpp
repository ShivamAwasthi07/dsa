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

int maxHeight2(Node* root, int &diameter){
    if(root == NULL){
        return 0;
    }
    int left = maxHeight2(root->left, diameter);
    int right = maxHeight2(root->right, diameter);
    diameter = max(diameter, left+right);
    return max(left, right)+1;
}

int solve_diameter(Node* root){
    int diameter = 0;
    int ans;
    maxHeight2(root, diameter);
    return diameter;
}

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

void leftPart(Node* root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        cout<<root->data<<" ";
        return;
    }
    cout<<root->data<<" ";
    if(root->left!=NULL){
        leftPart(root->left);
    }
    else if(!root->left && root->right != NULL){
        // cout<<root->data<<" ";
        leftPart(root->right);
    }
    

}

void rightPart(Node* root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        cout<<root->data<<" ";
        return;
    }
    if(!root->left){
        rightPart(root->right);
    }
    else if(!root->right){
        rightPart(root->left);
    }
}

void boundryLevel(Node* root){
    Node* temp = root;
    leftPart(temp->left);
    // rightPart(temp);
}

void solve(Node* root, int target, int& nearest){
    if(!root){
        return;
    }
    if(target <= root->data && nearest>= root->data ){
        nearest = min(nearest ,root->data);
    }
    solve(root->left, target, nearest);
    solve(root->right, target, nearest);
}

int ceilBT(Node* root, int target){
    int nearestGreater = INT_MAX;
    solve(root, target, nearestGreater);
    return nearestGreater;
}

int floorBST(Node* root, int key){
    int floor = INT_MAX;
    while(root){
        if(root->data == key){
            floor = root->data;
            return floor;
        }
        if(root->data > key){
            root = root->left;
        }
        else{
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}
Node* floorBSTNode(Node* root, int key){
    Node* floor = NULL;
    while(root){
        if(root->data == key){
            floor = root;
            return floor;
        }
        if(root->data > key){
            root = root->left;
        }
        else{
            floor = root;
            root = root->right;
        }
    }
    return floor;
}

void insertNode(Node*&root, int val){
    Node* ins = new Node(val);
    Node* floor_node = floorBSTNode(root, val);

    if(!floor_node->left){
        floor_node->left = ins;
    }
    else if(val > floor_node->left->data && floor_node->right == NULL){
        floor_node->right = ins;
    }
    else if(val < floor_node->left->data){
        Node* temp = floor_node->left;
        ins->right = temp; 
        floor_node->left = ins;
        return;
    }
    else if(val > floor_node->left->data && val < floor_node->right->data){
        Node* temp = floor_node->right;
        ins->right = temp; 
        floor_node->right = ins;
        return;
    }
}

int main(){
    Solution sol;
    Node* root = NULL;
    root = buildTree(root);
    cout<<floorBST(root, 8);
    // inorder(root);
    // Solution sol;
    // cout<<isBalanced(root).first<<" "<<isBalanced(root).second;

    // topOfBinaryTree(root);
    // vector<vector<int>> ans = sol.func(root);
    // int dia=0;
    // cout<<solve_diameter(root);
    // boundryLevel(root);
    // cout<<dia;
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
// 10 5 3 2 -1 -1 4 -1 -1 6 -1 9 -1 -1 13 11 -1 -1 19 -1 -1