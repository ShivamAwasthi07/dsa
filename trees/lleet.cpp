#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eval(string s){
        int val = 0;
        int mul = 1;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] == '-'){
                val = val*-1;
            }
            else{
                val += mul*(s[i]-'0');
                mul*=10; 
            }
        }
        return val;
    }
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(string s : tokens){
            if(s == "*" || s == "/" || s == "+" || s == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                cout<<a<<" "<<b<<endl;
                if(s == "*") {
                    st.push(a*b);
                }
                else if(s == "/") {
                    st.push(b/a);
                }
                else if(s == "+") {
                    st.push(a+b);
                }
                else if(s == "-") {
                    st.push(b-a);
                }
            }
            else{
                st.push(eval(s));
            }
        }
        return st.top();
    }
};

class NumberContainers {
public:
    vector <int> ans;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        cout<<ans.size()<<" change"<<endl;
        if(index > ans.size()){
            for(int i=ans.size();i<index;i++){
                ans.push_back(-1);
            }
            ans.push_back(number);
        }
        else if(index < ans.size()){
            ans[index] = number;
        }
        else{
            ans.push_back(number);
        }
        cout<<ans.size()<<" after change"<<endl;
    }
    
    int find(int number) {
        if(ans.size() == 0){
            return -1;
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i] == number){
                return i;
            }
        }
        return -1;
    }
};

int main(){
    vector <string> v = {"4","13","5","/","+"};
    // Solution sol;
    // int a = sol.evalRPN(v);
    NumberContainers num;
    num.change(1, 10);
    cout<<num.find(10)<<endl;
    num.change(1, 20);
    cout<<num.find(10)<<endl;
    cout<<num.find(20)<<endl;
    cout<<num.find(30)<<endl;
    return 0;
}