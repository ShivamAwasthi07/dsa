#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//these three are for checking if subset exist or not and equal sum partition

bool checkSubSetSumMemo(vector<int> v, int sum, int index, vector<vector<int> >&dp){
    if(sum < 0 || index == v.size()){
        return false;
    } 
    if(sum == 0){
        return true;
    }

    if(dp[index][sum] != -1){
        return dp[index][sum];
    }

    bool pick = checkSubSetSumMemo(v, sum-v[index], index+1, dp);
    bool nonpick = checkSubSetSumMemo(v, sum, index+1, dp);

    return dp[index][sum] = (pick || nonpick);
}

bool checkSubSetSumTab(vector<int> v, int sum, vector<vector<int> >&dp){
    int rows = dp.size();
    int cols = sum+1;

    for(int i = 0; i < cols ;i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i < rows ;i++){
        dp[i][0] = 1;
    }

    for(int i = 1 ; i < rows ; i++){
        for(int j = 1 ; j < cols ; j++){
             if(j >= v[i]){
                dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
            cout<<i<<" "<<j<<" "<<endl;
        }   
    }

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
                cout<<dp[i][j]<<" ";
        }   
        cout<<endl;
    }

    return dp[rows-1][cols-1];
}

bool equalSumPart(vector<int> v, int sum){
    if((sum&1) == 1){
        return false;
    }
    int num = sum/2;

    int rows = v.size();
    int cols = num+1;
    vector<vector<int> > dp(rows, vector<int> (cols, -1));

    return checkSubSetSumTab(v, num, dp);


}


//here we will write code for minimum subset difference

int minSubSetSumTab(vector<int> v, int sum, vector<vector<int> >&dp, int diff){
    int rows = dp.size();
    int cols = sum+1;

    for(int i = 0; i < cols ;i++){
        dp[0][i] = 0;
    }
    for(int i = 0; i < rows ;i++){
        dp[i][0] = 1;
    }

    for(int i = 1 ; i < rows ; i++){
        for(int j = 1 ; j < cols ; j++){
            if(j >= v[i]){
                dp[i][j] = dp[i-1][j-v[i]] || dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }   
    }
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < cols ; j++){
            cout<<dp[i][j]<<" ";
        }   
        cout<<endl;
    }

    cout<<endl<<endl;
    int ans = 0;
    for(int i = 0; i < sum+1 ;i++){
        if(dp[v.size()-1][i] == 1){
            cout<<abs(sum - 2 * i)<<" ";
            if(abs(sum - 2 * i) == diff){
                ans++;
            }
        }
    }

    return ans;
}
int main(){
    vector<int> v;

    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3); 

    int sum=0;
    for(int i = 0 ; i < v.size() ; i++){
        sum+=v[i];
    }

    int rows = v.size();
    int cols = sum+1;
    vector<vector<int> > dp(rows, vector<int> (cols, -1));

    int diff = 1;
    int ans = minSubSetSumTab(v, sum, dp, diff);

    cout<<ans;
    
    return 0;
}