#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int len = costs.size()/2;
        int a,b; 
        a = b = len;
        int sum=0;
        for(auto v : costs){
            if(v[0] <= v[1] && a){
                a--;
                sum+=v[0];
                cout<<"added "<<v[0]<<endl;
            }
            else if(v[0]>v[1] && b){
                b--;
                sum+=v[1];
                cout<<"added "<<v[1]<<endl;
            }
            else if(!b && a){
                sum+=v[0];
                a--;
                cout<<"added "<<v[0]<<endl;
            }
            else if(!a && b){
                sum+=v[1];
                b--;
                cout<<"added "<<v[1]<<endl;
            }
            // sum+=min(v[0],v[1]);
        }
        return sum;
    }
};

int main(){
Solution sol;
vector<vector <int>> cost = {{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}}; 
cout<< sol.twoCitySchedCost(cost);
    return 0;
}