#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    stack <int> s;
    string ans="";
    string smallestNumber(string pattern) {
        for(int i=1;i<=pattern.length()+1;i++){
            if(i == pattern.length()+1){
                s.push(pattern.length()+1);
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
            if(pattern[i-1] == 'D'){
                s.push(i);
            }
            else if(pattern[i-1] == 'I'){
                ans+=to_string(i);
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                }
            }
        }
    }
};

int main(){

    return 0;
}