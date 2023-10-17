#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lcs(string a, string b, int i, int j, vector<vector<int> > &v){
    cout<<"1";
    if(i == 0 || j == 0){
        return 0;
    }
    if(a[i] == b[j]){
        return 1+lcs(a, b, i-1, j-1, v);
    }
    if(v[i][j] != -1){
        return v[i][j];
    }
    return v[i][j] = max(lcs(a, b, i-1, j, v), lcs(a, b, i, j-1, v));
}

int main(){
    string a = "abcdgh";
    string b = "abdefhr";

    vector<vector<int> > v(a.length()+1, vector<int> (b.length()+1, -1));
    int ans = lcs(a, b, a.length(), b.length(), v);
    cout<<ans; 

    return 0;
}