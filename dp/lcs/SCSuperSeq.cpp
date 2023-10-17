#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void getStringSCS(string a, string b, vector<vector<int> > v){
    
    int i = v.size();
    int j = v[0].size();
    string s = "";
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            s = a[i-1]+s;
            i--;
            j--;
        } else if(v[i-1][j] > v[i][j-1]){
            s = a[i-1]+s;
            i--;
        } else if(v[i-1][j] <= v[i][j-1]){
            s = b[j-1]+s;
            j--;
        }
    }

    cout<<s;
    // cout<<"done";
}

int lcs(string a, string b, int len1, int len2){
    vector<vector<int> > v(len1+1, vector<int> (len2+1, -1));
    for(int i=0; i <= len1; i++){
        for(int j=0; j <= len2; j++){
            if(i == 0 || j == 0){
                v[i][j] = 0;
            } else if (a[i-1] == b[j-1]){
                v[i][j] = 1+v[i-1][j-1];
            } else {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    // getStringSCS(a, b, v);
    return v[len1][len2];
}

int main(){
    string a = "abcdgh";
    string b = "abdefhr";

    // int ans = lcs(a, reverse(a.begin(), a.end()), a.length(), a.length());

    // cout<<a.length()+b.length()-ans;
    return 0;
}