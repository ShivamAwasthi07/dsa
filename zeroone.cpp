#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<endl;
}

// class Solution {
// public:
//     vector<int> buildArray(vector<int>& nums) {
//     vector<int> v(nums.size());
//         for(int i=0;i<nums.size();i++){
//             v[i] = nums[nums[i]];
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        vector<vector<int>> v(score.size());
        vector <pair<int,int>> x;
        for(int i=0;i<score.size();i++){
            cout<<score[i][k]<<" "<<i<<endl;
            x.push_back(make_pair(score[i][k], i));
        }
        sort(x.begin(), x.end());

        for(int i=0;i<x.size();i++){
            // cout<<x[i].first<<" "<<x[i].second<<endl;
            printVector(score[x[x.size()-1-i].second]);
        }
        return v;
    }
};

int main(){
    vector<vector <int>> v1 = {{10,6,9,1},{7,5,11,2},{4,8,3,15}};
    int k=2;
vector<vector <int>> v2;
    Solution sol;
    v2 = sol.sortTheStudents(v1, k);
    // cout<<v2;
    // printVector(v2);
    return 0;
}