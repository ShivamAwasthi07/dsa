#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> nextGreaterElements(vector<int>& nums) {
        stack <int> st;
        stack <int> st2;
        vector <int> ans;
        st.push(-1);
        int maxi = INT_MIN;
        for(int i=nums.size()-1;i>=0;i--){
            maxi = max(maxi, nums[i]);
            if(!st.empty() && nums[i] < st.top()){
                st2.push(st.top());
                st.pop();
            }
            else{
                while(!st.empty() && nums[i] >= st.top()){
                    st.pop();
                }
                if(st.empty()){
                    st2.push(-1);
                }
                else{
                    st2.push(st.top());
                    st.pop();
                }
            }
            st.push(nums[i]);
        }
        while(!st2.empty()){
            ans.push_back(st2.top());
            st2.pop();
        }
        if(maxi > nums[nums.size()-1]){
            ans[ans.size()-1] = maxi;
        }
        return ans;
    }
};

int main(){
    vector <int> v = {1,2,3,4,3};
    Solution sol;
    sol.nextGreaterElements(v);
    return 0;
}