#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void deleteMid(stack <int> * s,int count, int size){
    if(size/2 == count){
        s->pop();
        return;
    }
    int x = s->top();
    s->pop();
    deleteMid(s, count+1, size);
    s->push(x);
}

void insertAtBottom(stack <int> * s, int size, int val){
    if(size==0){
        s->push(val);
        return;
    }
    int x = s->top();
    s->pop();
    insertAtBottom(s, size-1, val);
    s->push(x);
}

void traverseStack(stack<int> st){
    cout<<"entered";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

class Solution {
public:
    stack <int> s;
    int calPoints(vector<string>& operations) {
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "C"){
                s.pop();
            }
            else if(operations[i] == "D"){
                s.push(s.top()*2);
            }
            else if(operations[i] == "+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                int z = x+y;
                s.push(x);
                s.push(z);
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
    }
};

int main(){
    stack <int> s;
    vector <string> vec = {"5","2","C","D","+"};

    Solution sol;
    sol.calPoints(vec);

    return 0;
}
// int main(){
//     stack <int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50);
//     s.push(60);
//     traverseStack(s);
//     cout<<endl;
//     // deleteMid(&s, 0, s.size());
//     insertAtBottom(&s, s.size(), 10000);
//     traverseStack(s);
//     return 0;
// }