#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
public:
    stack <string> s;
    stack <string> s2;
    BrowserHistory(string homepage) {
        s.push(homepage);
    }
    
    void visit(string url) {
        s.push(url);
    }
    
    string back(int steps) {
        for(int i=0;i<steps;i++){
            s2.push(s.top());
            s.pop();
        }
        return s.top();
    }
    
    string forward(int steps) {
        for(int i=0;i<steps;i++){
            s.push(s2.top());
            s2.pop();
        }
        return s.top();
    }
};

int main(){
    while(true){
        
    }
    return 0;
}