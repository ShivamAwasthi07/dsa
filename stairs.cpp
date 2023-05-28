#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector <int> v(n, 0);
        v[0] = 0;
        v[1] = 1;
        v[2] = 2;
        if(n>=3){
            for(int i=3;i<=n;i++){
                v[i] = v[i-1]+v[i-2];
            }
            return v[n];
        }
        return v[n];
    }   
};

int main(){
    Solution sol;
    int a = sol.climbStairs(45);
    cout<<a;
    return 0;
}