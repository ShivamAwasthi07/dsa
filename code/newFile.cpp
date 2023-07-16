#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
     public:
     void solve(string str, int index, vector<string> &ans, string fullStr){
        if(index >= fullStr.length()){
            ans.push_back(str);
            return;
        }
        solve(str, index+1, ans, fullStr);
        solve(str+fullStr[index], index+1, ans, fullStr);
     }
     vector<string> findAll(string s){
        int index=0;
        vector<string> ans;
        string str = "";
        solve(str, index, ans, s);
        return ans;
     }

    void combinedSum(vector <int> & nums, int target, vector <int> &aux, vector<vector<int>> &ans, int sum, int index){
        if(sum > target || index >= nums.size()){
            return;
        }
        if(sum == target && index < nums.size()){
            ans.push_back(aux);
            return;
        }
        aux.push_back(nums[index]);
        combinedSum(nums, target, aux, ans, sum+nums[index], index);
        aux.pop_back();
        combinedSum(nums, target, aux, ans, sum, index+1);
    }

    vector<vector<int>> combinationSum(vector <int> & nums, int target){
        int index=0;
        int sum=0;
        vector<int> aux;
        vector<vector<int>> ans;
        combinedSum(nums, target, aux, ans, sum, index);
        return ans;
    }
};

int main(){
    Solution sol;
    int target = 8;
    vector<int> nums = {2,3,5};
    vector<vector<int>> ans = sol.combinationSum(nums, target);
    for(vector <int> v : ans){
        for(int a : v){
            cout<<a<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}