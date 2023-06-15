#include <iostream>
#include <bits/stdc++.h>
// #include <stack>
using namespace std;

class Solution{
     public:
     stack <int> st;
    void sortInsert(stack <int> &s, int num){
        if(s.empty() || (!s.empty() && s.top() < num)){
            s.push(num);
            return;
        }
        int n = s.top();
        s.pop();
        sortInsert(s, num);
        s.push(n);
    }
     void sortAStack(stack <int> &s){
        // st = *s;
        if(s.size() == 1){
            return;
        }
        int top = s.top();
        s.pop();
        sortAStack(s);
        sortInsert(s, top);
     }
    // cout<<st.top();
};

int main(){
    // Solution sol;
    // vector <int> v;
    // v.push_back
    // priority_queue <int> st;
    // st.push(5);
    // st.push(3);
    // st.push(-1);
    // st.push(10);
    // st.push(8);
    // sol.sortAStack(st);
    // st.pop();
    // cout<<st.top();
    return 0;
}