#include <iostream>
#include <stack>
using namespace std;

void insertInStack(stack <int>* st, int val){
    // traverseStack(st);
    if(st->size() == 0 || val >= st->top()){
        st->push(val);
        return;
    }
    int value = st->top();
    st->pop();
    insertInStack(st, val);
    st->push(value);
}

void sortStack(stack <int> & st){
    if(st.size() == 1){
        return;
    }
    int temp = st.top();
    st.pop();
    sortStack(st);
    insertInStack(&st, temp);
}

void traverseStack(stack <int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl<<endl;
}

int main(){
    stack <int> s;
    s.push(9);
    s.push(2);
    s.push(5);
    s.push(3);
    s.push(6);
    traverseStack(s);
    sortStack(s);
    traverseStack(s);
    return 0;
}