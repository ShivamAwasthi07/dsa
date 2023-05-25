#include <iostream>
// #include <vector>
#include <vector>
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

node* buildTree(node* root){
    int val;
    cout<<"enter data ";
    cin>>val;
    root = new node(val);

    if(val == -1){
        return NULL;
    }

    cout<<"Enter the left of "<<val<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right of "<<val<<endl;
    root->right = buildTree(root->right);

    return root;
}

bool identicalTrees(node* first, node* second){
    if(first == NULL && second == NULL){
        return true;
    }
    if((first == NULL && second != NULL)){
        return false;
    }
    if((first != NULL && second == NULL)){
        return false;
    }

    bool x = identicalTrees(first->left, second->left);
    bool y = identicalTrees(first->right, second->right);

    bool val = first->data == second->data;

    if(x && y && val){
        return true;
    }
    else{
        return false;
    }
}

void findAllSubsets(vector<string> &v, string inp, string out, int i){
    if(i >= inp.length()){
        cout<<out<<endl;
        v.push_back(out);
        return;
    }
 
    findAllSubsets(v, inp, out, i+1);

    char elem = inp[i];
    out.push_back(elem);
    findAllSubsets(v, inp, out, i+1);
}
void allSubsets( string s){
    int i=0;
    // string input = s;
    string out = "";
    vector <string> v;
    findAllSubsets(v, "abc", out, i);
    cout<<v.size();
    // return v;
}

int main(){
    // node* first = NULL;
    // node* second = NULL;

    // first = buildTree(first);
    // second = buildTree(second);

    // bool x = identicalTrees(first, second);
    // cout<<x;

    vector<string> * v;
    allSubsets("abc");
    // cout<<v->size();
    return 0;
}

// 5 10 -1 -1 15 -1 -1