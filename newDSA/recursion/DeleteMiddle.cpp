#include <iostream>
#include <stack>
using namespace std;

void DeleteSt(stack <int>* st, int count, int mid){
    if(count == mid){
        st->pop();
        return;
    }
    int temp = st->top();
    st->pop();
    DeleteSt(st, count+1, mid);
    st->push(temp);
}

void DeleteMiddle(stack <int>*st){
    int count=0;
    int mid = st->size()/2;
    
    DeleteSt(st, count, mid);
    // return st;
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
    // traverse(*st);
    DeleteMiddle(&st);
    // st->size();
    traverse(st);

    return 0;
}