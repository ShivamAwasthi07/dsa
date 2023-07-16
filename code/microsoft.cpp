#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
     public:
     int myFunction(vector <int> nums){
        map<char, int> m;
        for(int i : nums){
            string temp = to_string(i);
            for(char j : temp){
                m[j]++;
            }
        }
        int maxNum = INT_MIN;
        for(auto num : m){
            maxNum = max(num.second, maxNum);
        } 
        return maxNum;
     }
};

int main(){
    Solution sol;
    return 0;
}