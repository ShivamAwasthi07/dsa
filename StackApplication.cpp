#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack <int> st;
        vector <int> vec(h.size(),0);
        for(int i=h.size()-1;i>=0;i--){
            if(i==h.size()-1){
                st.push(h[i]);
                vec[i]=0;
            }
            else if(h[i] <= st.top()){
                st.push(h[i]);
                vec[i]=1;
            }
            else if(h[i] > st.top()){
                while(!st.empty() && h[i] > st.top()){
                    vec[i]++;
                    st.pop();
                }
                if(!st.empty()){
                    vec[i]++;
                }
                st.push(h[i]);
            }
        }
        return vec;
    }
};

int main(){
    Solution sol;
    vector <int> a = {10,6,8,5,11,9};
    vector <int> ans = sol.canSeePersonsCount(a);
    return 0;
}
