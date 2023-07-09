#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int, int> m;
        for(int x: nums){
            m[x]++;
            cout<<x<<" "<<m[x]<<endl;
            if(m[x]>1){
                ans.push_back(m[x]);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> ans = {4,3,2,7,8,2,3,1};
    Solution sol;
    vector<int> a;
    a = sol.findDuplicates(ans);
    for(int x : a){
        cout<<x<<" ";
    }
    return 0;
}