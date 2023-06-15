#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int kk) {
        double first = (double)quality[0]/(double)wage[0];
        cout<<first<<endl;
        double ans = (double) wage[0];
        int k=kk;
        k--;
        if(!k){
            return ans;
        }
        priority_queue <int> pq;
        for(int i=1;i<quality.size();i++){
            pq.push(quality[i]);
        }

        while(k--){
            ans+=(first*((double) pq.top()));
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector <int> q = {10,20,5};
    vector <int> w = {70,50,30};
    int k=2;
    cout<<sol.mincostToHireWorkers(q, w, k);
    return 0;
}