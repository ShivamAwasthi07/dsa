#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> v, int target, vector<int> &aux, vector<vector<int> > &ans, int index){
    if(target == 0){
        ans.push_back(aux);
        return;
    }
    if(index == v.size() || target < 0){
        return;
    }
    aux.push_back(v[index]);
    solve(v, target-v[index], aux, ans, index);
    aux.pop_back();
    solve(v, target, aux, ans, index+1);
}

int solve2(vector<int> v, int target, vector<vector<int> > &dp){
    int rows = dp.size();
    int cols = dp[0].size();

    for(int i=0; i < rows ;i++){
        for(int j=0; j < cols ;j++){
            if(j == 0 || i == 0){
                dp[i][j] = 0;
            } else if(j >= v[i]){
                dp[i][j] = max(dp[i][j-v[i]], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
}

int main(){
    vector<int> v;
    
    v.push_back(0);
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);

    int target = 8;

    vector<vector<int> > dp(v.size(), vector<int> (target+1, 0));
    int a = solve2(v, target, dp);

    // vector<int> aux;
    // vector<vector<int> > ans;
    // solve(v, target, aux, ans, 0);

    // for(auto i : ans){
    //     for(int j : i){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}