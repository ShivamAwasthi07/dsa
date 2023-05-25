#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
    public:

    void traverse(stack <int> st){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }

    void orderSet(stack <int>* st, int x){
        if(st->empty() || (!st->empty() && x>st->top())){
            st->push(x);
            return;
        }
            int z = st->top();
            st->pop();
            orderSet(st, x);
            st->push(z);
        
    }
    void SortedStack(stack <int>* st){
        int size = st->size();
        if(st->empty()){
            return;
        }
        int x = st->top();
        st->pop();
        SortedStack(st);
        orderSet(st, x);

    }
};

int main(){
    Solution sol;
    stack<int> s;
    s.push(9);
    s.push(-2);
    s.push(1);
    s.push(5);
    s.push(-9);
    sol.traverse(s);
    sol.SortedStack(&s);
    cout<<endl;
    sol.traverse(s);
    return 0;
}