#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void getStringLCS(string a, string b, vector<vector<int> > v){
    
    int i = v.size();
    int j = v[0].size();
    string s = "";
    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            s = a[i-1]+s;
            i--;
            j--;
        } else if(v[i-1][j] > v[i][j-1]){
            i--;
        } else if(v[i-1][j] <= v[i][j-1]){
            j--;
        }
    }

    cout<<s;
    // cout<<"done";
}

int lcs(string a, string b, int len1, int len2){
    vector<vector<int> > v(len1+1, vector<int> (len2+1, -1));
    // int maxi = INT_MIN; // ls substr
    for(int i=0; i <= len1; i++){
        for(int j=0; j <= len2; j++){
            if(i == 0 || j == 0){
                v[i][j] = 0;
            } else if (a[i-1] == b[j-1]){
                v[i][j] = 1+v[i-1][j-1];
                // maxi = max(maxi, v[i][j]); for lc substr
            } else {
                v[i][j] = max(v[i-1][j], v[i][j-1]); //for lcs length
                // v[i][j] = 0; //for ls substring length
            }
        }
    }

    getStringLCS(a, b, v);
    // return maxi;
    return v[len1][len2];
}

int main(){
    string a = "abcdgh";
    string b = "abdefhr";

    // string longer = a.length() >= b.length() ? a : b;
    // string shorter = a.length() < b.length() ? a : b;
    int ans = lcs(a, b, a.length(), b.length());
    cout<<ans; 

    return 0;
}