#include <iostream>
#include <bits/stdc++.h>
using namespace std;

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

    return v[len1][len2];
}

int main(){
    string a = "abcd";
    string b = "anc";

    string longer = a.length() >= b.length() ? a : b;
    string shorter = a.length() < b.length() ? a : b;
    int ans = lcs(shorter, longer, a.length(), b.length());

    cout<<"Deletions "<<longer.length()-ans<<endl;
    cout<<"Insertions "<<shorter.length()-ans<<endl;

    return 0;
}