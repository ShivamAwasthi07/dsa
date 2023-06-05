#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
    if (it != v.end()) 
    {
        int index = it - v.begin();
        return index;
    }
    else {
        
        return -1;
    }
}

class Solution {
public:
    set <int> s;
    vector <int> vec;
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(s.find(target-nums[i]) != s.end()){
                vec = {getIndex(nums, target-nums[i]), getIndex(nums,nums[i])};
                return vec;
            }
            else{
                s.insert(nums[i]);
            }
        }
    }
};

int main(){
    Solution sol;
    vector <int> nums = {3,3};
    int target = 6;
    vector <int> v = sol.twoSum(nums, target);
    cout<<v[0]<<" "<<v[1];
    return 0;
}