#include <iostream>
#include <stack>
using namespace std;


void insertAtBottom(stack <int>* st, int val){
    if(st->size() == 0){
        st->push(val);
        return;
    }
    int temp = st->top();
    st->pop();
    insertAtBottom(st, val);
    st->push(temp);
}

void ReverseStack(stack <int> * st){
    if(st->size() == 1){
        return;
    }
    int temp = st->top();
    st->pop();
    ReverseStack(st);
    insertAtBottom(st, temp);
}

void traverse(stack <int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    cout<<endl;
}

int main(){
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    traverse(st);
    ReverseStack(&st);
    traverse(st);
    return 0;
}