#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double ans = 0.0;
        int cnt=0;
        priority_queue<double, vector<double>, greater<double>> pq;
        for(vector<int> i : classes){
            double a = i[0]/(double)i[1];
            cout<<a<<" ";
            ans+=a;
        }
        cout<<ans<<endl<<endl;
        cout<<endl<<endl;
        double maxi = 0;
        for(int j=0;j<classes.size();j++){
            vector<int> i = classes[j];
            double ins = ((double)i[0]+(double)extraStudents)/((double)i[1]+(double)extraStudents);
            cout<<"updated "<<ins- (i[0]/(double)i[1])<<endl;
            if(ins- (i[0]/(double)i[1])> maxi && ins !=1){
                maxi = ins-(i[0]/(double)i[1]);
            }
            cout<<maxi<<endl<<endl;
        }
        ans = ans+maxi;    
        cout<<ans/4.0;
        return ans/(double) classes.size();
        
    }
};

int main(){
    vector<vector<int>> cl = {{2,4},{3,9},{4,5},{2,10}};
    Solution sol;
    double ans = sol.maxAverageRatio(cl, 4);
    return 0;
}