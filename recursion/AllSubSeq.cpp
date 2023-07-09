#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void helper(vector <int> &ans, int i, int len,vector <int> s, int ansstr){
    if(ansstr == len){
        // ans.push_back(ansstr);
        return;
    }
    helper(ans, i+1, len, s, ansstr);
    helper(ans, i+1, len, s, ansstr+s[i]);
}

vector<int> allSub(vector <int> s){
    int helpInt=0;
    int strlen = s.size();
    vector<int> ans;
    int ansstr = 0;
    helper(ans, helpInt, strlen, s, ansstr);
    return ans;
}

int main(){
    string s = "abc";
    vector<string> a = allSub(s);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}