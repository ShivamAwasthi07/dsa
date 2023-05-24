#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findVector(vector<int> &candidates, int target, int index, vector<int> &v){
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }
    if (index >= candidates.size()){
        return;
    }
}
    vector<vector<int>> ans;
    int sum=0;
    int index=0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector <int> v;
        findVector(candidates, target, 0, v);
        return ans;
    }
};

int main(){
    Solution sol;
    vector <int> v = {2,3,6,7};
    int target = 7;

    

    return 0;
}