#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void printV(vector<vector <int>>v){
        for (auto i : v){
            for(int x: i){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    void findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        int len = matches.size();
        int maxi = INT_MIN;
        for(vector <int> v : matches){
            m[v[1]]++;
            maxi = max(maxi, max(v[0], v[1]));
        }
        vector <int> v1;
        vector <int> v2;
        for(int i=1;i<=maxi;i++){
            cout<<"count "<< m[i]<<endl;
            if(m[i] == 0){
                v1.push_back(i);
            }
            else if(m[i]==1){
                v2.push_back(i);
            }
        }
        printV({v1, v2});
        // return {v1, v2};
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v = {{2,3}, {1,3}, {5,4}, {6,4}};
    sol.findWinners(v);
    return 0;
}